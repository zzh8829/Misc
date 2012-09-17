#include<windows.h>
#include<WinSock.h>
#include<stdio.h>
#include<string.h>
#pragma comment(lib,"WSOCK32")

typedef struct tagIPINFO
{
	u_char Ttl;		//Time To Live
	u_char Tos;		//Type Of Service
	u_char IPFlags; //IP flags
	u_char OptSize; //Size of options data
	u_char FAR *Options; //Options data buffer
}IPINFO,*PIPINFO;

typedef struct tagICMPECHO
{
	u_long Source;		//Source address
	u_long Status;		//IP status
	u_long RTTime;		//Round trip time in milliseconds
	u_short DataSize;	//Reply data size
	u_short Reserved;	//Unknown
	void FAR *pData;	//Reply data buffer
	IPINFO ipInfo;		//Reply options
}ICMPECHO, *PICMPECHO;
//ICMP.DLL Export Function Pointers
HANDLE(WINAPI *pIcmpCreateFile)(VOID);
BOOL(WINAPI *pIcmpCloseHandle)(HANDLE);
DWORD(WINAPI *pIcmpSendEcho)
	(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD);

//
//
void main(int argc, char **argv)
{
	WSADATA wsaData;		//WSADATA
	ICMPECHO icmpEcho;		//ICMP Echo reply buffer
	HANDLE	hndlIcmp;		//LoadLibrary()handle to ICMP.DLL
	HANDLE	hndlFile;		//Handle for IcmpCreateFile()
	LPHOSTENT pHost;		//Pointer to host entry structure
	struct in_addr iaDest; //Internet address structure
	DWORD	*dwAddress;		//IP Address
	IPINFO	ipInfo;			//IP Options structure
	int nRet;				//General use return code
	DWORD dwRet;			//DWORD return code
	int x;

	//Check arguments
	if(argc!=1)
	{
		fprintf(stderr,"\nSyntax:ping HostNameOrIPAddress\n");
		return;
	}

	//Dynamically load the ICMP.DLL
	hndlIcmp=LoadLibrary("ICMP.DLL");
	if(hndlIcmp==NULL)
	{
		fprintf(stderr,"\nCould not load ICMP.DLL\n");
		return;
	}

	//Retrieve ICMP function pointers
	pIcmpCreateFile=(HANDLE(WINAPI*)(void))
		GetProcAddress(hndlIcmp,"IcmpCreateFile");
	pIcmpCloseHandle=(BOOL(WINAPI *)(HANDLE))
		GetProcAddress(hndlIcmp,"IcmpCloseHandle");
	pIcmpSendEcho=(DWORD(WINAPI*)
		(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD))
		GetProcAddress(hndlIcmp,"IcmpSendEcho");

	//Cheak all the function pointers
	if(pIcmpCreateFile==NULL||
		pIcmpCloseHandle==NULL||
		pIcmpSendEcho==NULL)
	{
		fprintf(stderr,"\nError getting ICMP proc address\n");
		FreeLibrary(hndlIcmp);
		return;
	}

	//Init WinSock
	nRet=WSAStartup(0x0101,&wsaData);
	if(nRet)
	{
		fprintf(stderr,"\nWSAStartup() error:%d\n",nRet);
		WSACleanup();
		FreeLibrary(hndlIcmp);
		return;
	}
	//Cheak WinSock version
	if(0x0101!=wsaData.wVersion)
	{
		fprintf(stderr,"\nWinSock version 1.1 not supported\n");
		WSACleanup();
		FreeLibrary(hndlIcmp);
		return;
	}

	//Lookup destination
	//Use inet_addr() to determine if we're dealing with a name
	//or an address
	iaDest.s_addr=inet_addr(argv[1]);
	if(iaDest.s_addr==INADDR_NONE)
		pHost=gethostbyname(argv[1]);
	else
		pHost=gethostbyaddr((const char*)&iaDest,
		sizeof(struct in_addr),AF_INET);
	if(pHost==NULL)
	{
		fprintf(stderr,"\n%s not found\n",argv[1]);
		WSACleanup();
		FreeLibrary(hndlIcmp);
		return;
	}

	//Tell the user what we're doing
	printf("\nPinging %s[%s]",pHost->h_name,
		inet_ntoa((*(LPIN_ADDR)pHost->h_addr_list[0])));

	//Copy the address
	dwAddress=(DWORD*)(*pHost->h_addr_list);

	//Get an ICMP echo request handle
	hndlFile=pIcmpCreateFile();
	for(x=0;x<4;x++)
	{
		//Set some reasonable default valuse
		ipInfo.Ttl=255;
		ipInfo.Tos=0;
		ipInfo.IPFlags=0;
		ipInfo.OptSize=0;
		ipInfo.Options=NULL;
		//icmpEcho.ipInfo.Ttl=256;
		//Reqest an ICMP echo
		dwRet=pIcmpSendEcho(
			hndlFile,		//Handle from IcmpCreateFile()
			*dwAddress,		//Destination IP address
			NULL,			//Pointer to buffer to send
			0,				//Size of buffer in bytes
			&ipInfo,		//Request options
			&icmpEcho,		//Request options
			sizeof(struct tagICMPECHO),
			5000);			//Time to wait in milliseconds
		//Print the results
		iaDest.s_addr=icmpEcho.Source;
		printf("\nReply from%s	Time=%ldms	TTL=%d",
					inet_ntoa(iaDest),
					icmpEcho.RTTime,
					icmpEcho.ipInfo.Ttl);
		if(icmpEcho.Status)
		{
			printf("\nError:icmpEcho.Status=%ld",
				icmpEcho.Status);
			break;
		}
	}
	printf("\n");
	//Close the echo request file handle
	pIcmpCloseHandle(hndlFile);
	FreeLibrary(hndlIcmp);
	WSACleanup();
}