#include <cstdio>
#include <ctime>
#include <cmath>
const int maxp = 1000001; // 总数量 自己随便改... 
const int sp = 1000;
int P[sp],pn;
bool p[maxp];
bool prime(int n)
{
	if(!n&1)
	return false;
	for(int i=3;i*i<n+2;i+=2)
	if(n%i==0)
	return false;
	return true;
}
int main()
{
	// 开始计时... 
	clock_t t1 = clock();
	P[pn++]= 2;
	for(int i=3;i<sp;i+=2)
		if(prime(i))
		 P[pn++] = i;
	for(int i=0;i!=pn;i++)
		for(int j=2;j*P[i]<maxp;j++)
			p[j*P[i]]=true;	 
	//  输出数字 忽略... 
	for(int i=2;i!=maxp;i++)
		if(!p[i])
			printf("%d ",i);
		
	// 输出计时 
	printf("Done\n%0.4f\n", (float)(clock()-t1)/CLOCKS_PER_SEC );
	getchar();
	return 0;
}
