#include <iostream>
#include <cstdio>
using namespace std;
inline int max(int a,int b){
	return a>b?a:b;
}
inline int min(int a,int b){
	return a<b?a:b;
}
struct Dot
{
	Dot(){}
	Dot(int a,int b)
	{
		x=a;
		y=b;
	}
	int x;
	int y;
};
struct Vec
{
	Vec(){}
	Vec(Dot a,Dot b)
	{
		beg = a;
		end = b;
	}
	Dot beg;
	Dot end;
};
int multi(Vec a, Vec b)
{
	int x1,x2,y1,y2;
	x1 = a.beg.x-a.end.x;
	x2 = b.beg.x-b.end.x;
	y1 = a.beg.y-a.end.y;
	y2 = b.beg.y-b.end.y;
	return x1*y2-y1*x2;
}
int cross=0;
Vec tel;
bool intersect(Vec tel,Vec l)
{
//	cout << tel.beg.x <<endl;
	if( max(tel.beg.x,tel.end.x) < min(l.beg.x,l.end.x) ||
		max(l.beg.x,l.end.x) < min(tel.beg.x,tel.end.x) ||
		max(tel.beg.y,tel.end.y) < min(l.beg.y,l.end.y) ||
		max(l.beg.y,l.end.y) < min(tel.beg.y,tel.end.y))
		return false;
	if( ((multi(Vec(tel.beg,l.beg),tel) * multi(Vec(tel.beg,l.end),tel) > 0) ||
	(multi(Vec(l.beg,tel.beg),l) * multi(Vec(l.beg,tel.end),l) > 0)) )
		return false;
	return true;
}

int main()
{
	
	int a,b,c,d,e,f,g,h;
	while(cin >> a >> b >> c >>d >>e >> f>> g >>h)
	{
		cout << intersect(Vec(Dot(a,b),Dot(c,d)),Vec(Dot(e,f),Dot(g,h))) <<endl;
	}
	system("pause");
	return 0;
}
