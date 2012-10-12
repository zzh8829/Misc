//1785

#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >>x;
    if ( x>=  1    && x<= 4	  )cout<< "few"<<endl;
    if ( x>=  5    && x<= 9	  )cout<< "several"<<endl;
    if ( x>=  10   && x<= 19  )cout<< "pack"<<endl;
    if ( x>=  20   && x<= 49  )cout<< "lots"<<endl;
    if ( x>=  50   && x<= 99  )cout<< "horde"<<endl;
    if ( x>=  100  && x<= 249 )cout<< "throng"<<endl;
    if ( x>=  250  && x<= 499 )cout<< "swarm"<<endl;
    if ( x>=  500  && x<= 999 )cout<< "zounds"<<endl;
    if ( x>=  1000            )cout<< "legion"<<endl;
    return 0;
}
