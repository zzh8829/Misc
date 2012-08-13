#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t,s,h;
	cin >> t >> s >> h;
	string ans="";
	string line="";
	char ln = '\n';
	char sp = ' ';
	char st = '*';
	for(int i=0;i!=t;i++)
	{
		ans += st;
		ans += string(s,sp);
		ans += st;
		ans += string(s,sp);
		ans += st;
		ans += ln;
	}
	ans = ans + st + string(s,st)
			+st+string(s,st)
			+st + ln;
	for (int i=0;i!=h;i++)
	{
		ans += sp;
		ans += string(s,sp);
		ans += st;
		ans += string(s,sp);
		ans += sp;
		ans += ln;
	}
	cout << ans;
	system("pause");
	return 0;
}
