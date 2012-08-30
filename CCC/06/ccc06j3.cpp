#include <iostream>
#include <string>
using namespace std;

int key[27] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int num[27] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

int main()
{
	string in;
	while(cin >> in && in != "halt")
	{
		int sum = 0;
		for(int i=0;i!=in.size();i++)
		{
			sum+=num[in[i] - 'a'];
			if(i!=in.size()-1&&key[ in[i] - 'a' ] == key[ in[i+1] - 'a' ] )
				sum +=2;
		}
		cout << sum <<endl;
	}
	return 0;
}
