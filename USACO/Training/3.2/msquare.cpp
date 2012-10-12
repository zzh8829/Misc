/*
ID: zzh8829
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

string fin = "";
set<string> ss;
queue<Node> Q;

struct Node{
	Node(string _st,string _str,int _d){
		st = _st;
		str = _str;
		d=_d;
	}
	string st,str;
	int d;
};

Node DFS(){
	if(fin=="12345678") return Node("","",0);
	Q.push(Node("12345678","",0));
	ss.insert("12345678");
	while(!Q.empty()){
		Node cur = Q.front();
		Q.pop();
		string C = cur.st;
		string A(C.rbegin(),C.rend());
		if(A==fin) return Node(A,cur.str+"A",cur.d+1);
		if(!ss.count(A)){
			ss.insert(A);
			Q.push(Node(A,cur.str+"A",cur.d+1));
		}
		string B(C[3]+C.substr(0,3)+C.substr(5)+C[4]);
		if(B==fin) return Node(B,cur.str+"B",cur.d+1);
		if(!ss.count(B)){
			ss.insert(B);
			Q.push(Node(B,cur.str+"B",cur.d+1));
		}
		swap(C[1],C[2]);swap(C[1],C[5]);swap(C[1],C[6]);
		if(C==fin) return Node(C,cur.str+"C",cur.d+1);
		if(!ss.count(C)){
			ss.insert(C);
			Q.push(Node(C,cur.str+"C",cur.d+1));
		}
	}
}
int main(){
	ifstream cin("msquare.in");
	ofstream cout("msquare.out");
	char in;
	for(int i=0;i!=8;i++){
		cin >> in;
		fin += in;
	}
	Node n = DFS();
	cout << n.d << endl<< n.str << endl;
	return 0;
}
