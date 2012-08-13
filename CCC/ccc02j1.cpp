#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	switch(n)
	{
	case 1:
		cout << "      \n      *\n      *\n      *\n      \n      *\n      *\n      *\n     \n";break;
	case 2:
		cout << " * * *\n      *\n      *\n      *\n * * *\n*      \n*      \n*      \n * * *\n";	break;
	case 3:
		cout << " * * *\n      *\n      *\n      *\n * * *\n      *\n      *\n      *\n * * *\n";	break;
	case 4:
		cout << "      \n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n      \n";	break;
	case 5:
		cout << " * * *\n*      \n*      \n*      \n * * *\n      *\n      *\n      *\n * * *\n";	break;
	case 6:
		cout << " * * *\n*      \n*      \n*      \n * * *\n*     *\n*     *\n*     *\n * * *\n";	break;
	case 7:
		cout << " * * *\n      *\n      *\n      *\n      \n      *\n      *\n      *\n      \n";	break;
	case 8:
		cout << " * * *\n*     *\n*     *\n*     *\n * * *\n*     *\n*     *\n*     *\n * * *\n";	break;
	case 9:
		cout << " * * *\n*     *\n*     *\n*     *\n * * *\n      *\n      *\n      *\n * * *\n";	break;
	case 0:
		cout << " * * *\n*     *\n*     *\n*     *\n      \n*     *\n*     *\n*     *\n * * *\n";	break;
	}
	return 0;
}
