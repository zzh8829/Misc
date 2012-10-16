#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

string ms[13]={
	"January", "February", "March", "April", "May", 
	"June", "July", "August", "September", "October",
	"November", "December"
};

int check(int d,int m,int y)
{
	if(m>12 || d > 31) return 0;
	if(y%4!=0 && m==2 && d>28) return 0;
	if(y<25) return 2;
	return 9;	
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	for(int cs=0;cs!=n;cs++)
	{
		string line;
		getline(cin,line);
		int p = 0;
		while(p<line.size()-7 && line.size()>6)
		{
			if(!p || ispunct(line[p-1]) || isspace(line[p-1]))
			{				
				if( line[p+2] == '/' && line[p+5] == '/' &&
					(p==line.size()-8 || ispunct(line[p+8]) || isspace(line[p+8])))
				{
					int d = 10*(line[p]-'0')+line[p+1]-'0';
					int m = 10*(line[p+3]-'0')+line[p+4] - '0';
					int y = 10*(line[p+6]-'0')+line[p+7] -'0';
					int c = check(d,m,y);	
					if(c==2) line.insert(p+6,"20");
					if(c==9) line.insert(p+6,"19");
					p+=8;				
				}			
				else if( line[p+2] == '.' && line[p+5] == '.' &&
					(p==line.size()-8 || ispunct(line[p+8]) || isspace(line[p+8])))
				{
					int y = 10*(line[p]-'0')+line[p+1]-'0';
					int m = 10*(line[p+3]-'0')+line[p+4] - '0';
					int d = 10*(line[p+6]-'0')+line[p+7] -'0';
					int c = check(d,m,y);	
					if(c==2) line.insert(p,"20");
					if(c==9) line.insert(p,"19");	
					p+=8;										
				}	
				else
				{
					for(int i=0;i!=12;i++)	
					if(ms[i]==line.substr(p,ms[i].size()) && line[p+ms[i].size()+3] ==',' &&
						p+ms[i].size()+6<line.size())
					{
						p+=ms[i].size();
						if( line[p] == ' ' && isdigit(line[p+1]) && isdigit(line[p+2]) && line[p+4]==' ' 
							&& isdigit(line[p+5]) && isdigit(line[p+6]))
						{
							int m = i+1;
							int d = 10*(line[p+1]-'0')+line[p+2]-'0';
							int y = 10*(line[p+5]-'0')+line[p+6]-'0';
							int c = check(d,m,y);	
							if(c==2) line.insert(p+5,"20");
							if(c==9) line.insert(p+5,"19");	
							p+=6;
						}
						break;
					}			
				}		
			}
			p++;
		}
		cout << line << endl;	
	}
	return 0;
}

