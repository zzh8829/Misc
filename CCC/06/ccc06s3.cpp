#include <cstdio>
using namespace std;
inline int max(int a,int b){
	return a>b?a:b;
}
inline int min(int a,int b){
	return a<b?a:b;
}
struct Dot{
	int x;
	int y;
};
struct Vec{
	Vec(){}
	Vec(Dot a,Dot b){
		beg = a;
		end = b;
	}
	Dot beg;
	Dot end;
};
int multi(Vec a, Vec b)
{
	int x1 = a.beg.x-a.end.x;
	int x2 = b.beg.x-b.end.x;
	int y1 = a.beg.y-a.end.y;
	int y2 = b.beg.y-b.end.y;
	return x1*y2-y1*x2;
}
int cross,n,m;
Vec tel;
bool intersect(Vec l)
{
	if( max(tel.beg.x,tel.end.x) < min(l.beg.x,l.end.x) ||
		max(l.beg.x,l.end.x) < min(tel.beg.x,tel.end.x) ||
		max(tel.beg.y,tel.end.y) < min(l.beg.y,l.end.y) ||
		max(l.beg.y,l.end.y) < min(tel.beg.y,tel.end.y) ||
		multi(Vec(tel.beg,l.beg),tel) * multi(Vec(tel.beg,l.end),tel) > 0 ||
		multi(Vec(l.beg,tel.beg),l) * multi(Vec(l.beg,tel.end),l) > 0 )
		return false;
	return true;
}

int main()
{
	scanf("%d%d%d%d%d",&tel.beg.x,&tel.beg.y,&tel.end.x,&tel.end.y,&n);
	for(int i=0;i!=n;i++)
	{
		bool f = false;
		scanf("%d",&m);
		Dot in[33];
		for(int j=0;j!=m;j++)
			if(scanf("%d%d",&in[j].x, &in[j].y)&& j && !f)
				if(intersect(Vec(in[j-1],in[j])))
					f = true;
		if(!f)
			if(intersect(Vec(in[m-1],in[0])))
				f = true;
		if(f) cross++;
	}
	printf("%d\n",cross);
	return 0;
}
