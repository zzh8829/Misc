/*
ID: zzh8829
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

#define INF  1e200
#define EP  1e-10
#define MAXV  300
#define PI  3.14159265
const int M=100000+5;
 
struct P 
{
	P(double a=0, double b=0):x(a),y(b){} 
    double x,y;
};
struct V 
{
    P s;
    P e;
    V(P a=P(), P b=P()):s(a),e(b){}
};

int n;
P p[2000], e;
V s[2000];
bool ok[2000];

double sqr(double x)
{
    return x * x;
}

double dist(P p1,P p2) 
{
    return sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ;
}

double multi(P sp,P ep,P op)
{
    return(sp.x-op.x)*(ep.y-op.y)-(ep.x-op.x)*(sp.y-op.y);
}
bool online(V l,P p) 
{
    return((multi(l.e,p,l.s)==0) &&( ( (p.x-l.s.x)*(p.x-l.e.x)<=0 )&&( (p.y-l.s.y)*(p.y-l.e.y)<=0 ) ) );
}
P midpoint(P a, P b)
{
    return P((a.x + b.x) / 2, (a.y + b.y) / 2);
}
bool intersect(V u,V v) 
{
    return ( (max(u.s.x,u.e.x)>=min(v.s.x,v.e.x))&&
        (max(v.s.x,v.e.x)>=min(u.s.x,u.e.x))&&
        (max(u.s.y,u.e.y)>=min(v.s.y,v.e.y))&&
        (max(v.s.y,v.e.y)>=min(u.s.y,u.e.y))&&
        (multi(v.s,u.e,u.s)*multi(u.e,v.e,u.s)>=0)&& 
        (multi(u.s,v.e,v.s)*multi(v.e,u.e,v.s)>=0));
}

bool intersect_A(V u,V v) {
    return ((intersect(u,v))&&
        (!online(u,v.s))&&
        (!online(u,v.e))&&
        (!online(v,u.e))&&
        (!online(v,u.s)));
}

bool watch(int k, V a)
{
    if (dist(a.s, a.e) < 1e-5) return false;
    int flag = 0;
    for (int v = 1; v <= n; v++) if (v != k)
    {
        if (intersect(V(e, a.s), s[v]) && intersect(V(e, a.e), s[v]))
        {
            flag = 1;
            break;
        }
        if (intersect_A(V(e, a.s), s[v]) || intersect_A(V(e, a.e), s[v]))
        	flag = 2;
    }
    if (!flag) return true;
    if (flag == 1) 
    	return false;
    else 
    	return (watch(k, V(a.s, midpoint(a.s, a.e))) 
    		|| watch(k, V(midpoint(a.s, a.e), a.e)));
}
int main()
{
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
    scanf("%d", &n);
    scanf("%lf%lf", &e.x, &e.y);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &p[i].x, &p[i].y);
    for (int i = 1; i < n; i++)
        s[i] = V(p[i], p[i + 1]);
    s[n] = V(p[1], p[n]);
    int cnt = 0;
    memset(ok, false, sizeof(ok));
    for (int i = 1; i <= n; i++)
    if (watch(i, s[i]))
    {
        cnt++;
        ok[i] = true;
    }
    printf("%d\n", cnt);
    for (int i = 1; i < n - 1; i++) if (ok[i])
    	printf("%d %d %d %d\n", (int)s[i].s.x, (int)s[i].s.y, (int)s[i].e.x, (int)s[i].e.y);
    if (ok[n]) printf("%d %d %d %d\n", (int)s[n].s.x, (int)s[n].s.y, (int)s[n].e.x, (int)s[n].e.y);
    if (ok[n - 1]) printf("%d %d %d %d\n", (int)s[n - 1].s.x, (int)s[n - 1].s.y, (int)s[n - 1].e.x, (int)s[n - 1].e.y);
    return 0;
}
/*
#include <iostream>
#include <cstdio>
using namespace std;

bool ok[5001];

struct P
{
	P(float a=0,float b=0):x(a),y(b){}
	float x,y;
}pt[2005],view;

struct V
{
	V(P a=P(0,0),P b=P(0,0)):beg(a),end(b){}
	P beg,end;
}seg[1001];


int multi(V u,V v)
{
	return ((u.end.x-u.beg.x)*(v.end.y-v.beg.y)-(u.end.y-u.beg.y)*(v.end.x-v.beg.x));
}

bool intersect(V a, V b)
{
	if(multi(a,V(a.beg,b.beg))*multi(a,V(a.beg,b.end))<0
	&& multi(b,V(b.beg,a.beg))*multi(b,V(b.beg,a.end))<0 )
		return true;
	return false;
}

V toleft(V newv,V org)
{


}

V toright(V newv,V org)
{


}

bool fail(V left,V right)
{


}

bool watch(V left, V right)
{
	int f = multi(left,right);
	cout << f << endl;
	for (int i = 0; i < n; ++i)
	{
		left = toleft(V(view,seg[i].beg),left);
		right = toright(V(view,seg[i].end),right);
		if(fail(left,right))
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int x,y;
	int n;
	cin >> n;
	cin >> view.x >> view.y;
	for (int i = 0; i < n; ++i)
		cin >> pt[i].x >> pt[i].y;
	for (int i = 0; i < n-1; ++i)
	{
		seg[i].beg = pt[i];
		seg[i].end = pt[i+1];
	}
	seg[n-1].beg = pt[0];
	seg[n-1].end = pt[n-1];
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)if (i!=j)
	if (intersect(seg[i],seg[j]))
	{
		cout <<"NOFENCE" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		while(true)
		{
			int t1,t2,t3,t4;
			cin >> t1 >> t2 >> t3 >> t4;
			cout << multi(V(view,seg[i].beg),V(P(t1,t2),P(t3,t4)))  << endl;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(ok[i])
		{
			//printf("%.f %.f %.f %.f\n", seg[i].beg.x,seg[i].beg.y,seg[i].end.x,seg[i].end.y);
		}
	}
	return 0;
}

*/