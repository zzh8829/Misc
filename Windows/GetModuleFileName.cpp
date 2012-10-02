#include <tchar.h>
#include <iostream>
#include <windows.h>
using namespace std;

int _tmain( int argc, _TCHAR* argv[] )
{
	TCHAR szEXEPath[ 2048 ];
	DWORD nChars = GetModuleFileName( NULL, szEXEPath, 2048 );
	cout << szEXEPath << '\n';
	cout << nChars << " characters.\n";

	return 0;
}
