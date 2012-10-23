#include <iostream>
#include <string>
using namespace std;

string w="CAMBRIDGE";

int main()
{
	string in;
	cin >> in;
	int fd = in.find_first_of(w);
	while(fd!=-1)
	{
		in[fd]='$';
		fd = in.find_first_of(w);
	}
	for(int i=0;i!=in.size();i++)
	if(in[i]!='$')
	cout << in[i];
	cout << endl;
	return 0;
}
		
