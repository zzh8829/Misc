#include <iostream>
using namespace std;

int main()
{
	int nm=101;
	int sum1=0;
	int sumn=(1+100)*100/2;
	int sum2=sumn*sumn;
	for(int i=1;i!=nm;i++)
	    sum1+=i*i;
	cout << sum2-sum1 <<endl;
	return 0;
}
