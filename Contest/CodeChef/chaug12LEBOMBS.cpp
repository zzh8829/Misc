#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int num;
		cin >> num;
		string bs;
		cin >> bs;
		string af(bs);
		for(int i=0;i!=num;i++)
		{
			if(bs[i]=='1')
			{
			// ->
			if( i!=num-1 )
					af[i+1] = 'e';
			if( i!=0)
					af[i-1] = 'e';
			af[i] = 'e';
			}
		}
		int cnt = 0;
		for(int i=0;i!=num;i++)
		{
			if(af[i] == '0')
			cnt ++;
		}
		cout << cnt <<endl;
	}
	return 0;
}
			
