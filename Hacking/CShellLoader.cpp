#include <iostream>
#include <cstdio>
#include <windows.h>
using namespace std;


int main()
{
	DWORD err;
	HINSTANCE hDLL = LoadLibrary("CShell.dll");
	if(hDLL != NULL) 
	{
		printf("Library has been loaded\n");
	}
	else
	{
		err = GetLastError();
		printf("Load Library FAILED\n");
	}	
	system("pause");
	return 0;
}
