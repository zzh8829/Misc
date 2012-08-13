#include<iostream>
#include<string>
using namespace std;
string f(string s){string k="";for(int i=0;i!=s.size();i++){if(s[i]=='%')k+=" ";else if(s[i]=='Q')k+="\n";else k+=s[i]+9;}return k;}
int main(){
    cout<<f(".*%.)%.(%.'%-0%-/%-.%--%-,Q.+%+*%+)%+(%+'%*0%*/%*.%-+Q.,%++%)(%)'%(0%(/%(.%*-%-*Q.-%+,%))%%.%%-%%,%(-%*,%-)Q..%+-%)*%%/%%(%%+%(,%*+%-(Q./%+.%)+%%0%%)%%*%(+%**%-'Q.0%+/%),%('%((%()%(*%*)%,0Q/'%+0%)-%).%)/%)0%*'%*(%,/Q/(%,'%,(%,)%,*%,+%,,%,-%,.")<<endl;    return 0;
}
