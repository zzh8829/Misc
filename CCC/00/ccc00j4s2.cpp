#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main()
{
	vector<float> vi;
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		float in;
		cin >> in;
		vi.push_back(in);
	}
	int state;
	while(cin >> state && state !=77)
	{
		if(state == 99)
		{
			int num;
			cin >> num;
			float per;
			cin >> per;
			float left = vi[num-1]*per/100.0;
			float right = vi[num-1]-left;
			vi[num-1]=left;
			vi.insert(vi.begin()+num,right);
		}
		else if(state == 88)
		{
			int num;
			cin >> num;
			vi[num]+=vi[num-1];
			vi.erase(vi.begin()+num-1);			
		}
	}
	for(int i=0;i<vi.size();i++)
	{
		if(i)
		cout << " ";
		cout << int(vi[i]+0.5) ;
	}
	cout <<endl;
	system("pause");
	return 0;
}
