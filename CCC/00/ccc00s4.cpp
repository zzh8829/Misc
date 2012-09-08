#include <iostream>
#include <cstdio>

using namespace std;

int m[5281];
int g[33]; 
int main()
{
	int n,gs,in;
	cin >> n >> gs;
	for(int i=0;i!=gs;i++)
	{
		cin >> g[i];
		m[g[i]]++;
	}
	for(int i=1;i<=n;i++) if( m[i] )		
		for(int k=0;k!=gs;k++)
			if( !m[i+g[k]]|| m[i]+1 < m[i+g[k]] )
				m[i+g[k]] = m[i]+1;	
	if(m[n]!=0)
	printf("Roberta wins in %d strokes.\n",m[n]);
	else
	printf("Roberta acknowledges defeat.\n");
	system("pause");
	return 0;
}
