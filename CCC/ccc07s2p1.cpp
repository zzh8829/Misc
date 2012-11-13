#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct P{
	P(int _x=0,int _y=0):x(_x),y(_y){}
	int x,y;
	bool operator<(const P &rp)const 
	{
		return x<rp.x || (x==rp.x && y<rp.y);
	}
};

int crossProduct(P o,P a,P b)
{
	return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

vector<P> convex(vector<P> ps)
{
	int n = ps.size(),k=0;
	vector<P> H(2*n);
	sort(ps.begin(),ps.end());
	for(int i=0;i<n;i++)
	{
		while(k>=2 && crossProduct(H[k-2],H[k-1],ps[i])<=0)k--;
		H[k++] = ps[i];
	}

	for(int i=n-2,t=k+1;i>=0;i--)
	{
		while(k>=t && crossProduct(H[k-2],H[k-1],ps[i])<=0)k--;
		H[k++] = ps[i];
	}
	H.resize(k);
	return H;
}

int main()
{
	vector<P> ps;
	int n, x, y;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		cin >> x >> y;
		ps.push_back(P(x,y));
	}
	ps = convex(ps);
	float ar = 0;
	for(int i=1;i<ps.size()-1;i++)
		ar+=abs(crossProduct(ps[0],ps[i],ps[i+1]))/2.0;
	cout << int(ar/50.0) << endl;
	return 0;
}