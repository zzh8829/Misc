#include <iostream>
using namespace std;
int main()
{
	float a ,b;
	while(cin >> a >> b)
	{
		float t = a/(b*b);
		if(t>25.0)
		cout <<	"Overweight\n";
		else if(18.5 <= t && 25.0>=t)
		cout << "Normal weight\n";
		else if(t<18.5)
		cout << "Underweight\n";
	}
	return 0;
}