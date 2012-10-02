//Newton Method
#include <stdio.h>

float x = 10; 
float error = 1e-3; // 精度
float m_pow(float base,int m)
{
	float a=1;
	for(int i=0;i!=m;i++)
		a*=base;
	return a;
}

float solve(int coe,int mi)
{
	float t = 0.0;
	int c=0;
	do
	{
		x=x-(m_pow(x,mi)-coe)/(mi*m_pow(x,mi-1));
		t = m_pow(x,mi)-coe;
		t = t>0?t:-t;
		if((c++)>(1<<30)){printf("OUT OF RANGE\n");x=-1;break;}
	}while(t>error);
	return x;
}

int main()
{
	int coe=10000, pow=4;
//scanf("%d%d",&coe,&pow); 自己输入 第一个是x第二个是y 求x的y次方根
	printf("%f",solve(coe,pow));
	return 0;
}
