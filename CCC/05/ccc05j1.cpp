#include <cstdio>
#include <iostream>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	float A,B;
	if(a<100) a = 100;
	A = (a-100)*25+b*15+c*20;
	if(a<250) a = 250;
	B = (a-250)*45+b*35+c*25;
	A=A/100;
	B=B/100;

	printf("Plan A costs %0.2f\nPlan B costs %0.2f\n",A,B);
	if(A>B)
	printf("Plan B is cheapest.");
	else if( A<B)
	printf("Plan A is cheapest.");
	else 
	printf ("Plan A and B are the same price.");
	printf("\n");
	system("pause");
	return 0;
}
