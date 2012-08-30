#include <iostream>
using namespace std;
int main()
{
	char* t ="TroyMartian" ;
	char* v ="VladSaturnian" ;
	char* g ="GraemeMercurian" ;

	int a,b;
	cin >> a >> b;
	if(a>=3 && b <=4)
	cout << t <<endl;
	if(a<=6 && b >=2 )
	cout << v <<endl;
	if(a<=2 && b <=3 )
	cout << g <<endl;
	return 0;
}