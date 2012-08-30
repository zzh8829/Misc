#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int score[255];

int main()
{
	char order[5]={'C','D','H','S'};
	string hint[255];
	score[0]=3;
	score[1]=2;
	score[2]=1;
	score['J'] = 1;
	score['Q'] = 2;
	score['K'] = 3;
	score['A'] = 4;
	hint['C'] = "Clubs ";
	hint['D'] = "Diamonds ";
	hint['H'] = "Hearts ";
	hint['S'] = "Spades ";
	hint['T'] = "Total ";
	string card;
	cin >> card;
	int s = 0;
	int c= 0;
	
	cout << "Cards Dealt Points" <<endl;
	
	for(int i=0;i!=4;i++)
	{
		c++;
		int n=0;
		int p =0;
		cout << hint[order[i]] ;
		while(card[c]!=order[i+1] && c<card.size())
		{		
			p+=score[card[c]];
			cout << card[c] << " ";
			n++;
			c++;
		}
		p+= score[n];
		cout << p <<endl;
		s+=p;
	}
	cout << hint['T'] << s <<endl;
	system("pause");
	return 0;
}
