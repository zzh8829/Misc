//Babylonian Square Roots
#include <iostream>
using namespace std;

float SQRT(float a,float error)
{
	float x =a;
	while( (x-a/x>0?x-a/x:a/x-x) >error)
		x = (x+a/x)2
	return x;
}

int main()
{
	cout << SQRT(2,0.000001) << endl;
	return 0;
}