#include <iostream>
#include <string>
using namespace std;


string a[12] = {"CU",":-)",":-(",";-)",":-P","(~.~)","TA","CCC","CUZ","TY","YW","TTYL"};
string q[12] = {"see you","I'm happy","I'm unhappy","wink","stick out my tongue","sleepy","totally awesome","Canadian Computing Competition","because","thank-you","you're welcome","talk to you later"};
	
int main()
{
	string in;
	while(cin >> in)
	{
		if(in == a[0]) 
		cout << q[0] <<endl; 
		else if(in == a[1])
	    cout << q[1] <<endl;
		else if(in == a[2])
	    cout << q[2] <<endl;
		else if(in == a[3])
	    cout << q[3] <<endl;
		else if(in == a[4])
	    cout << q[4] <<endl;
		else if(in == a[5])
	    cout << q[5] <<endl;
		else if(in == a[6])
	    cout << q[6] <<endl;
		else if(in == a[7])
	    cout << q[7] <<endl;
		else if(in == a[8])
	    cout << q[8] <<endl;
		else if(in == a[9])
	    cout << q[9] <<endl;
		else if(in == a[10])
	    cout << q[10] <<endl;
		else if(in == a[11])
	    cout << q[11] <<endl;
		else cout << in << endl;
	}
	system("pause");
	return 0;
}
