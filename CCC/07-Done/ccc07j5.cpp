#include <iostream>
using namespace std;
bool motel[7010];
int ways[7010];
int h[14] = {0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int main()
{
	int a,b,n,in;
	cin >> a >> b >> n;
	for(int i=0;i!=n && cin >> in;++i) motel[in] = true;
	for(int i=0;i!=14;i++) motel[h[i]] = true;
	ways[0] = 1;
	for(int i=0;i<=7000;++i) if(motel[i]) for(int j=i+a;j<=i+b && j<=7000;++j)
		 if(motel[j]) ways[j]+=ways[i];
	cout << ways[7000] <<endl;
	return 0;
}
