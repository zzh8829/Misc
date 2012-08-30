#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
bool m[210][450];
int row,col;
bool go(char d,int n)
{
	int gc = 0,gr = 0;
	if(d=='l')	gc=-1;
	if(d=='r') 	gc=1;
	if(d=='u')	gr=-1;
	if(d=='d') 	gr=1;
	printf("%d %d ",col-205+gc*n,-row-gr*n);
	for(int i=0;i!=n;i++)
	{
		if(m[row+gr][col+gc])
		return false;
		col+=gc;
		row+=gr;
		m[row][col]=1;
	}
	return true;
}

void rgo(char d,int n)
{
	int gc = 0,gr = 0;
	if(d=='l')	gc=-1;
	if(d=='r') 	gc=1;
	if(d=='u')	gr=-1;
	if(d=='d') 	gr=1;
	for(int i=0;i!=n;i++)
	{
		col+=gc;
		row+=gr;
		m[row][col]=1;
	}
}


int main()
{
	row=0;col=205;
	char d;
	int n;
	rgo('d' ,3);rgo('r' ,3);rgo('d' ,2);rgo('r' ,2);
	rgo('u' ,2);rgo('r' ,2);rgo('d' ,4);rgo('l' ,8);
	rgo('u' ,2);
	while(cin >> d >>n && d!='q')
	{
		if(go(d,n))
			printf("safe \n");
		else
		{
			printf("DANGER \n");
			break;
		}
	}	
	system("pause");
	return 0;
}
