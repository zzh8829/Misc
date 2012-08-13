#include <iostream>

using namespace std;

int main()
{
	char c;
	int max=0;
	int n=0;
	int num['z'+1]={0};
	char name[11];
	char in;
	while(cin >> in )
	{
		name[n++]=in;
		num[in]++;
	}
	for(int i='z';i!='a'-1;i--)
	{
		if(num[i]>=1)
		{
            max= num[i];
			c=i;
			break;
		}
	}

	for(int i=0;i!=max;i++)
	cout << c;
	cout << endl;
	return 0;
}
