#include <iostream>
#include <string>
using namespace std;

int main()
{
	char sp = ' ';
	char st = '*';
	char ln = '\n';
	int n;
	cin >> n;
	string pat[20];
	int up = (n+1)/2;
	for(int i=0;i!=up;i++)
	{
	int cnt = i*2+1;
	string line;
	line+= string(cnt,st) + string(2*(n-cnt),sp) + string(cnt,st) + ln;
	pat[i]= line;
	}
	for(int i=0;i!=up;i++)
	cout << pat[i];
	for(int i=up-2;i!=-1;i--)
	cout << pat[i];
	system("pause");
	return 0;
}
