#include <iostream>
using namespace std;
char bmp[251][251]={'.'};
int n=0,m=0;

void create(int n, int m)
{
	for(int i=0;i!=250;i++)
	for(int j=0;j!=250;j++)
	bmp[i][j]={'.'}
	for(int i=0;i!=n;i++)
	for(int j=0;j!=m;j++)
	bmp[i][j]=o;
}

void clear(int n, int m)
{
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
	bmp[i][j]=o;
}

void color(int x, int y, char c)
{
	bmp[x][y]=c;
}

void vline(int x,int y1,int y2 ,char c)
{
	for(int i=y1;i!=y2+1;i++)
	bmp[x][i]=c;
}

void hline(int x1,int x2,int y,char c)
{
	for(int i=x1;i!=x2+1;i++)
	bmp[i][y]=c;
}

void fill(int x1,int x2,int y1,int y2,char c)
{
	for(int i=x1;i!=x2+1;i++)
	for(int j=y1;j!=y2+2;j++)
	bmp[i][j]=c;
}

void region(int x,int y,char c)
{
	char r=bmp[x][y];
	if(y<m&&bmp[x][y+1]==r)
	region(x,y+1,c);
	if(y>0&&bmp[x][y-1]==r)
	region(x,y-1,c);
	if(x>0&&bmp[x-1][y]==r)
	region(x-1,y,c);
	if(x<n&&bmp[x+1][y]==r)
	region(x+1,y,c);
}

void save(string name)
{
	cout << name <<endl;
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=m;j++)
		cout << bmp[i][j];
		cout << endl;
	}
}


int main()
{
	char act,c;
	bool exit=false;
	int x1,x2,y1,y2;
	while(cin >> act && exit==false)
	{
		switch(act)
		{
		case 'I': 
			{
				cin >> n>> m;
				create(n,m);
				break;
			}
		case 'C':
			{
				clear(n,m);
				break;
			}
		case 'L':
			{
				cin >> x >> y >> c;
				color( x,y,c);
				break;
			}
		case 'V':
			{
				cin >> x>>y1>>y2>>c;
				vline(x,y1,y2,c);
				break;
			}
		case 'H':
			{
				cin >> x1>>x2>>y>>c;
				hline(x1,x2,y,c);
				break;
			}
		case 'K':
			{
				cin >> x1>>x2>>y1>>y2>>c;
				fill(x1,x2,y1,y2,c);
				break;
			}
		case 'F':
			{
				cin >> x >>y >>c;
				region(x,y,c);
				break;
			}
		case 'S':
			{
				cin << name;
				save(name);
				break;
			}
		case 'X':
			{
				exit=true;
				break;
			}
		default:
			{
				exit=true;
				break;
			}
		}
	}
	
	system("pause");
	return 0;
}