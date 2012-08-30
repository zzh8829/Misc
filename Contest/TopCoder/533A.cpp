#include <iostream>
#include <cstdio>

using namespace std;

class PlatypusDuckAndBeaver
{
public:
	int minimumAnimals(int W, 
		int B, int T)
	{
		int duck,plat,beav;
		plat = B+2*T-W/2;
		duck = B-plat;
		beav = T-plat;
		return plat+duck+beav;
	}
};


int main()
{
	PlatypusDuckAndBeaver a;
	cout << a.minimumAnimals(0,0,0) <<endl;
	system("pause");
	return 0;
}
