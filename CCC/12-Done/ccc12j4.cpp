#include <iostream>
#include <string>
using namespace std;

int K ;

char decode(char letter,int pos)
{
	int shift = (3*pos + K)%26;
	if(int(letter)-int('A')+1-shift <= 0)
	shift-=26;
	return char(int(letter)-shift);
}

int main()
{
	cin >> K ;
	string word;
	string ans="";
	cin >> word;
	for(int i=0;i!=word.size();i++)
	{
		ans += decode(word[i],i+1) ;
	}
	cout << ans <<endl;
	system("pause");
	return 0;
}
