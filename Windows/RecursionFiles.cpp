#include <windows.h>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

int count;
int lines;
bool checkExtension(string name)
{
	if(name.size()>4)
	{
		string e = name.substr(name.size()-4);
		for(int i=0;i!=e.size();i++)
			e[i]=tolower(e[i]);
		if(e==".cpp" || e==".hpp")
			return true;
	}
	if(name.size()>2)
	{
		string e = name.substr(name.size()-2);
		for(int i=0;i!=e.size();i++)
			e[i]=tolower(e[i]);
		if(e==".c" || e==".h")
			return true;
	}
	if(name.size()>3)
	{
		string e = name.substr(name.size()-3);
		for(int i=0;i!=e.size();i++)
			e[i]=tolower(e[i]);
		if(e==".cc" )
			return true;
	}
	return false;
}

void countLines(char * filePath)
{
	count++;
	ifstream fin(filePath);
	string in;
	while(getline(fin,in))
	for(int i=0;i!=in.size();i++)
	if(!isspace(in[i]))
	{
		lines++;
		break;
	}	
	fin.close();	
}

void find(const char * lpPath)
{
    char szFind[MAX_PATH];
    WIN32_FIND_DATA FindFileData;
    strcpy(szFind,lpPath);
    strcat(szFind,"\\*.*");
    HANDLE hFind=::FindFirstFile(szFind,&FindFileData);
    if(INVALID_HANDLE_VALUE == hFind)  return;
    
    while(TRUE)
    {
        if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            if(FindFileData.cFileName[0]!='.')
            {
				char szFile[256];
                strcpy(szFile,lpPath);
                strcat(szFile,"\\");
                strcat(szFile,FindFileData.cFileName);
                find(szFile);
            }
        }
        else if(checkExtension(FindFileData.cFileName))
    	{
			char szFile[256];
            strcpy(szFile,lpPath);
            strcat(szFile,"\\");
            strcat(szFile,FindFileData.cFileName);
           // cout << szFile << endl;
            countLines(szFile);
        }
        if(!FindNextFile(hFind,&FindFileData))    break;
    }
    FindClose(hFind);
}

int main()
{
	string folderPath;
	while(1)
	{
		count = 0;
		lines = 0;
		cout << "Enter Folder Path" << endl;
		cin >> folderPath;
		if(folderPath == "EXIT")
			break;
		find(folderPath.c_str());
		printf("%d files are end with 'cpp','c','h','hpp','cc'\n",count);
		printf("Total %d of non-empty lines\n\n",lines);
	}
	printf("\nThank You...:) @zzh8829 \n");
	return 0;
}
