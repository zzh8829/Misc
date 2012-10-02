#include <windows.h>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std; 

// Returns an empty string if dialog is canceled
string openfile(char *filter = "All Files (*.*)\0*.*\0", HWND owner = NULL) {
	OPENFILENAME ofn;
	char fileName[MAX_PATH] = "";
	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = owner;
	ofn.lpstrFilter = filter;
	ofn.lpstrFile = fileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = "";

	string fileNameStr;

	if ( GetOpenFileName(&ofn) )
	fileNameStr = fileName;

	return fileNameStr;
}

BOOL ForceDelFile(const char *szFileToDel)
{
    char cTempFileName[0x80];
    char cTempPathName[0x100];
    char cFileName[0x100];
	
	if(GetTempPath(256,cTempPathName)==0){
		return FALSE;
	}
	
	if(szFileToDel[0]!='c' && szFileToDel[0]!='C')
	{
		sprintf(cTempPathName,"*:\\~TEMP",8);
		cTempPathName[0]=szFileToDel[0];
		printf("%s\n",cTempPathName);
		CreateDirectory(cTempPathName,NULL);
		SetFileAttributes(cTempPathName,
			FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_DIRECTORY);
	}

    if(GetTempFileName(cTempPathName, "~", 0, cTempFileName) == 0){
        return FALSE;
    }

    if(MoveFileEx(szFileToDel, cTempFileName, 1) == 0){
        return FALSE;
    }
	
	SetFileAttributes(cTempFileName,
			FILE_ATTRIBUTE_HIDDEN);
	
    if(MoveFileEx(cTempFileName, NULL, 4) == 0){
        return FALSE;
    }
	
    return TRUE;
}


int main(int argc, char* argv[])
{
	
    if(ForceDelFile(openfile().c_str()) == TRUE){
        printf("Done");
    }
    else{
        printf("Error %d", GetLastError());
    }
    return 0;
}

