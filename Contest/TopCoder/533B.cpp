#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

void eval(vector<int>& vi,vector<int>& stack,int i)
{
	if(
}

class Suminator
{
public:
	int findMissing(vector<int> vi,int wR)
	{
		vector<int> stack;
		stack.push_back(0);
		for(int i=0;i!=vi.size();i++)
		{
			if(vi[i]==-1)
			{
				 if ( vi[i] == 0) 
			{
				int sum = stack.back();
				stack.pop_back();
				sum+=stack.back();
				stack.pop_back();
				stack.push_back(sum);
		    }
			else 
			{
		         stack.push_back(vi[i]);
			}
		   
		}
		
		cout << stack.back() <<endl;
		if(stack.back()==wR)
			return 0;
		return -1;
	}
};


int main()
{
	int v[100] = {-1, 7, 3, 0, 1, 2, 0, 0};
	vector<int> vi(v,v+8);
	Suminator s;
	cout << s.findMissing(vi,13) <<endl;	
	system("pause");
	return 0;
}
