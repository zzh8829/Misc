#include <iostream>

using namespace std;

int main()
{
	int a,b,c,d,s;
	cin >> a >> b >> c >> d >> s;
	int ns= s/(a+b);
	int bs = s/(c+d);
	int nr = s-(a+b)*ns;
	int br = s-(c+d)*bs;
	int np = (a-b)*ns;
	int bp = (c-d)*bs;
	if(nr > a )
		np = np + a - (nr-a);
	else 
		np = np + nr;
	if(br > c)
		bp = bp + c - (br-c);
	else
		bp = bp + br;
	if(np>bp)
	cout << "Nikky" <<endl;
	else if(np<bp)
	cout << "Byron" <<endl;
	else 
	cout << "Tied" <<endl;
	return 0;
}
