#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
	float input[65537]={0.0};
	int id=0;
	float in=0.0;
	int t = clock();
	int t2 = 0;
	while(cin>>in)
	{
		input[id]=in;
		id++;
		t2=clock();
		if (t2-t > 1000)
		break;
	}
	int idd=id;
	while(id>-1)
	{
		input[id]=sqrt(input[id]);
		id--;
	}
	for(int i=idd-1;i!=-1;i--)
		cout<<input[i] <<endl;
	system("pause");
	return 0;
}
