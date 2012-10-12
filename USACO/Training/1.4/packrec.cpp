/*
ID: zzh8829
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int total,MIN=32767,a[5][3],answer[100][3];
void pack(int x,int y)
{
	if (x*y>MIN) return;
	if (x*y<MIN)
	{
		MIN=x*y;
		total=0;
	}
	if (x>y) swap(x,y);
	for (int i=1;i<=total;i++)
		if (x==answer[i][1] && y==answer[i][2])
			return;
	answer[++total][1]=x; answer[total][2]=y;
}

int main()
{
	ifstream cin("packrec.in");
	ofstream cout("packrec.out");
	for (int i=1;i<5;i++)
		cin >> a[i][1] >> a[i][2];
	for (int a1=1;a1<5;a1++)
	for (int a2=1;a2<5;a2++) if (a1!=a2)
	for (int a3=1;a3<5;a3++) if (a3!=a2&&a3!=a1)
	{
		int a4=10-a1-a2-a3;
		for (int b1=1;b1<3;b1++)
		for (int b2=1;b2<3;b2++)
		for (int b3=1;b3<3;b3++)
		for (int b4=1;b4<3;b4++)
		{
			int h1=a[a1][b1],h2=a[a2][b2],h3=a[a3][b3],h4=a[a4][b4];
			int w1=a[a1][3-b1],w2=a[a2][3-b2],w3=a[a3][3-b3],w4=a[a4][3-b4];
			
			int width=w1+w2+w3+w4,height=max(max(max(h1,h2),h3),h4);
			pack(width,height);
		
			width=max(w1+w2+w3,w4);
			height=max(max(h1,h2),h3)+h4;
			pack(width,height);
		
			width=max(w1+w2,w3)+w4;
			height=max(max(h1,h2)+h3,h4);
			pack(width,height);
		
			width=w1+w2+max(w3,w4);
			height=max(max(h1,h2),h3+h4);
			pack(width,height);
		
			height=max(h1+h3,h2+h4);
			if (h3>=h2+h4) width=max(w1,w3+max(w2,w4));
			if (h3>h4&&h3<h2+h4) width=max(w1+w2,w3+max(w2,w4));
			if (h3<h4&&h4<h1+h3) width=max(w1+w2,w4+max(w1,w3));
			if (h4>=h1+h3) width=max(w2,w4+max(w1,w3));
			if (h3==h4)	width=max(w1+w2,w3+w4);
			pack(width,height);
		}
	}
	for (int i=1;i<total;i++)
	for (int j=i+1;j<=total;j++)
	if (answer[i][1]>answer[j][1])
	{
		swap(answer[i][1],answer[j][1]);
		swap(answer[i][2],answer[j][2]);
	}
	cout << MIN << endl;
	for (int i=1;i<=total;i++)
		cout << answer[i][1] <<" " <<answer[i][2] << endl;
	return 0;
}
