#include <iostream>
#include <string>
using namespace std;

int cnt[256] ;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin.ignore();
		string a;
		getline(cin,a);
		for(int j=0;j!=a.size();j++)
		{
			cnt[ (char)a[j] ]++;
		}
	}
	int dif = cnt['S']+cnt['s']-cnt['T']-cnt['t'];
	if(dif >= 0)
	cout << "French" <<endl;
	else 
	cout << "English" <<endl;
	
	
	system("pause");
	return 0;
}
