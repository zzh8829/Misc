#include <iostream>
using namespace std;

int main()
{
for(int i=1;i!=101;i++)
{
if(i%3==0)
{
	if(i%5==0)
		cout << "FizzBuzz ";
	else
		cout << "Fizz ";
} else if(i%5==0 && i%3 !=0)
cout << "Buzz ";
else
cout << i <<" ";
}
cout <<endl;
system("pause");
return 0;
}
