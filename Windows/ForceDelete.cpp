#include <cstdio>
#include <windows.h>

BOOL ZapDelFile(char *szFileToDel)
{
    char cTempFileName[0x80];
    char cTempPathName[0x100];
    char cFileName[0x100];
	
	if(GetTempPath(256,cTempPathName)==0){
		return FALSE;
	}
	
    if(GetTempFileName(cTempPathName, "_@", 0, cTempFileName) == 0){
        return FALSE;
    }

    if(MoveFileEx(szFileToDel, cTempFileName, 1) == 0){
        return FALSE;
    }

    if(MoveFileEx(cTempFileName, NULL, 4) == 0){
        return FALSE;
    }

    return TRUE;
}

void usage(char *n) {
    printf("usage: %s fullFilePath\n", n);
    exit(0);
}


int main(int argc, char* argv[])
{
    if (argc != 2)
        usage(argv[0]);

    if(ZapDelFile(argv[1]) == TRUE){
        printf("Done");
    }
    else{
        printf("Error %d", GetLastError());
    }
    return 0;
}

