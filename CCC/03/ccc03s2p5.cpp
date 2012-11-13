#include <cstdio>

const int maxn = 65536;
int s[maxn],o[maxn],v[maxn];
int t,BEG,END=-1;

inline int* nxt(int i){
	return s+i%maxn;
}

inline int* nxtout(int i){
	return o+i%maxn;
}

int main()
{
	for(int i=0;scanf("%d",nxt(i)); ++i)
	{
		if(*nxt(i)==0) break;
		v[*nxt(i)]++;
		while(v[*nxt(i)] > 1)
			v[*nxt(t++)]--;
		if(i+BEG > END +t)
		{
			for(int k=t>END?t:END+1;k<=i;k++) 
				*nxtout(k) = *nxt(k);
			END = i;
			BEG = t;
		}
	}
	for(int i=BEG;i<=END;i++)
		printf("%d\n",*nxtout(i));
	return 0;
}