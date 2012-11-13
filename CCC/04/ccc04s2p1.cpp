#include <iostream>
#include <string>
using namespace std;

int mk[256];
int num[256];
char l;
int v,a,n,maxs;
string wd;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		
		cin >> l >> v >> a;
		mk[l]=v;
		num[l]=a;
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{		
		cin >> wd;
		int cnt[256]={0};
		int sc = 0;
		int ok = 1;
		for(int i=0;i!=wd.size();i++)
		{
			cnt[wd[i]]++;
			sc+=mk[wd[i]];
			if(cnt[wd[i]]>num[wd[i]]){
				ok = false;
				break;
			}	
		}
		if(ok && sc>maxs) maxs =sc;
	}
	cout << maxs << endl;
	return 0;
}