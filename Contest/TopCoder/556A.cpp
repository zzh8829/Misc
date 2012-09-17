#include <iostream>
#include <string>
#include <map>
using namespace std;
class ChocolateBar
{
public:
	int maxLength(string str)
	{
        int n = str.length();
        int  prefixlen[51];
        prefixlen[n] = 0;
        int maxlenstart [51];
        maxlenstart[n] = n;
        int maxlenend[51];
        maxlenend[n] = n-1;
         
        for(int i=n-1;i>=0;i--){
            char c = str[i];
            //caculate prefixlen[i] by prefixlen[i+1]
            int j=0,k;
            for(j=0,k=i+1;j<prefixlen[i+1];j++,k++){
                if(c == str[k]){                 
                    break;
                }
            }
            prefixlen[i] = j+1;
             
            //caculate maxlenstart[i] and maxlenend[i]
            maxlenstart[i] = maxlenstart[i+1];
            maxlenend[i] = maxlenend[i+1];
            if(maxlenstart[i+1] == i+1){
                if(prefixlen[i] == prefixlen[i+1] + 1){
                    maxlenstart[i] = i;
                }
            }else{
                //update the max len for i...n-1
                if(maxlenend[i] - maxlenstart[i] + 1 < prefixlen[i]){
                    maxlenstart[i] = i;
                    maxlenend[i] = i + prefixlen[i] - 1;
                }
            }           
        }
        return maxlenend[0] - maxlenstart[0] + 1;
    }
};

int main()
{
	string in;
	while(cin >> in)
	{
		cout << ChocolateBar().maxLength(in) <<endl;
	}
	return 0;
}

