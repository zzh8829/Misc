#include <windows.h>

int WINAPI WinMain( HINSTANCE hInstance,HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	MessageBox (NULL,TEXT("Hello, Windows!"),TEXT("HelloMsg"),
		MB_YESNO|MB_ICONINFORMATION);
	return 0;
}
