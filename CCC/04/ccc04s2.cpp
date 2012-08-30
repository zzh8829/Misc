#include <iostream>
#include <cstdio>

using namespace std;
int score[101][101],n,k,in;

int main()
{
	cin >> n >> k;
	for(int i=0;i!=k;i++)
	for(int j=0;j!=n;j++)
	{
		cin >> in;
		if(i)
		in+=score[i-1][j];
		score[i][j] = in;
	}
	int max =-100000;
	for(int i=0;i!=n;i++)
	if(max < score[k-1][i])
	max = score[k-1][i];
	for(int i=0;i!=n;i++)
	if(score[k-1][i] == max)
	{
		int worst=1;		
		for(int j=0;j!=k;j++)
		{
			int rank = 1;
			for(int k=0;k!=n;k++)
			if(score[j][k]>score[j][i])
			rank++;
			if(rank>worst)
			worst = rank;
		}
		printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n",i+1,max,worst );
	}
	system("pause");
	return 0;
}
