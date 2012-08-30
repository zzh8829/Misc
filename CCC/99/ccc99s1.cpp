#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string cards[53];
int A,B;
void f(int turn,int n,int c)
{
	int score = 0;
	for(int i=c+1;i<=c+n ;i++)
	{
		if(i==52||cards[i][0]=='j' || cards[i][0]=='q' ||
		cards[i][0]=='k' ||cards[i][0]=='a')
		{
			score = 0;
			break;
		}
		score++;
	}
	if(score)
	{
		if(turn)
		{
			printf("Player B scores %d point(s).\n",score);
			B+=score;
		}
		else
		{
			printf("Player A scores %d point(s).\n",score);
			A+=score;
		}			
	}
}

int main()
{
	int s[256];
	s['j'] = 1;
	s['q'] = 2;
	s['k'] = 3;
	s['a'] = 4;
	for(int i=0;i!=52;i++)
		getline(cin,cards[i]);
	for(int i=0;i!=52;i++)
		f(i%2,s[ cards[i][0] ],i);
	printf("Player A: %d point(s).\nPlayer B: %d point(s).\n",A,B);
	system("pause");
	return 0;
}
