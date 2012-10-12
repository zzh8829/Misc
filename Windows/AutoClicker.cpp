#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int x = 400;
	int y = 300;
	int slpTime=1;
	int dx[5]={100,-100,-100,0};
	int dy[5]={0,0,0,-100};
	while(!GetAsyncKeyState('I'))
		Sleep(1000);
    while(true)
	{
		for(int i=0;i!=2;i++)
		{
			int tx = x+dx[i];
			int ty = x+dy[i];
			SetCursorPos(tx,ty);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, tx, ty, 0, 0);
	   		mouse_event(MOUSEEVENTF_RIGHTUP, tx, ty, 0, 0);
			Sleep(slpTime*2000);
			if (GetAsyncKeyState(VK_ESCAPE))
				exit(0);
		}
		if (GetAsyncKeyState(VK_ESCAPE))
			exit(0);
		else continue;
	}
	return 0;
}

