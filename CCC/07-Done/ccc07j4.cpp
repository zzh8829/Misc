#include <iostream>
#include <string>
using namespace std;

int na[256],nb[256];

bool an(string a,string b)
{
	for(int i=0;i!=a.size();i++)
	{
		if (a[i]!=' ')
		na[ (char)a[i] ]++;
	}
	for(int i=0;i!=b.size();i++)
	{
		if (b[i]!=' ')
		nb[ (char)b[i] ]++;
	}
	for(int i=0;i!=255;i++)
	{
		if(na[i] !=nb[i])
		return false;
	}
	return true;
}

int main()
{

	string a,b;
	getline(cin ,a );
	getline(cin ,b );
	
	if(an(a,b))
	cout << "Is an anagram." <<endl;
	else 
	cout << "Is not an anagram."<<endl;
	
	return 0;
}
