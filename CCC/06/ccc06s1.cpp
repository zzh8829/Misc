#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string f,m,s;
int main()
{
	int x,ok;
	cin >> f >> m >> x;
	for(int n=0;n!=x;n++)
	{
		ok = true;
		cin >> s;
		for(int i=0;i!=5;i++)
		{
			if(islower(s[i]))
			if(!(  (islower(f[2*i])||islower(f[2*i+1])) &&
				   (islower(m[2*i])||islower(m[2*i+1])) ) )
			{
				ok = false;
				break;	
			}			
			else
			if( !(isupper(f[2*i])||isupper(f[2*i+1]) ||
				 isupper(m[2*i])||isupper(m[2*i+1]) ) )
			{
				ok = false;
				break;
			}				
		}
		if(ok)
		cout << "Possible baby." <<endl;
		else
		cout << "Not their baby!" <<endl;
	}
	return 0;
}
