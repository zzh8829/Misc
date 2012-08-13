/*
ID: zzh8829
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Person {
	int init;
	int recive;
	int mod;
	string name;
}friends[10]={0,0,0,""};

int main()
{
ifstream fin("gift1.in");
ofstream fout("gift1.out");
int nums;
fin>> nums;
for(int num=0;num!=nums;num++)
{
	string inName;
	fin >>inName;
	friends[num].name=inName;
}
for(int run=0;run!=nums;run++)
{
	string name;
	fin>> name;
	for(int findI=0;findI!=nums;findI++)
    	if(friends[findI].name==name)
    	{
        	int init,gives,give;
        	fin >> init>> gives;
        	friends[findI].init=init;
        	if(gives==0)
        	{
                friends[findI].mod=0;
                give=0;
            }
            else
        	{
                friends[findI].mod=init%gives;
            	give=init/gives;
            }
        	for(int fs=0;fs!=gives;fs++)
        	{	
        		string gname;
        		fin >> gname;
        		for(int find=0;find!=nums;find++)
        			if(friends[find].name==gname)
        				friends[find].recive+=give;		
    	   }
        }
}
for(int show=0;show!=nums;show++)
	fout<< friends[show].name <<" "<< friends[show].recive+friends[show].mod-friends[show].init<<endl;
return 0;
}
