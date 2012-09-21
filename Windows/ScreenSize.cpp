#include <windows.h>
#include <tchar.h>
#include <cstdio>

int CDECL MessageBoxPrintf( TCHAR * szCaption, TCHAR* szFormat, ... )
{
	TCHAR szBuffer [1024];
	va_list pArgList;
	va_start(pArgList,szFormat);
	_vsntprintf( szBuffer,sizeof(szBuffer)/sizeof(TCHAR),szFormat,pArgList);
	va_end(pArgList);
	return MessageBox(NULL,szBuffer,szCaption,0);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
					LPSTR szCmdLine,int iCmdShow)
{
	int cxScreen,cyScreen;
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);
	MessageBoxPrintf(TEXT("ScreenSize"),
		TEXT("The screen is %i pixels wide by %i pixels high."),
		cxScreen,cyScreen);
	return 0;
}
