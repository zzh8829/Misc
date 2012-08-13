 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<string>
#include<algorithm>
#include<complex>
#include<numeric>
using namespace std;
double x[10], y[10], t[10];
bool solve(int i, int j, int k)
{
    double x1, y1, x2, y2, t1, t2;
    x1 = x[j] -x[i];
    x2 = x[k] -x[i];
    y1 = y[j] -y[i];
    y2 = y[k] -y[i];
    t1 = t[j] -t[i];
    t2 = t[k] -t[i];
    
    double A1 = x1*x1 + y1*y1 - t1*t1;
    double A2 = x2*x2 + y2*y2 - t2*t2;
    double A = A1*y2-A2*y1, B = A1*x2-A2*x1, C = A1 * t2 - A2 * t1;
    double cita = atan2(B, A);
    double sum = asin(- C/sqrt(A*A+B*B+1e-15));
    
    double alpha = sum - cita;
    double r;
    if (abs(A1)>abs(A2))
        r = A1/(t1 + x1 *cos(alpha) + y1 * sin(alpha))/2;
    else
        r = A2/(t2 + x2 *cos(alpha) + y2 * sin(alpha))/2;
    
    if (r<0)
    {
        sum = - sum + 3.141592653579;
        alpha = sum - cita;
        if (abs(A1)>abs(A2))
            r = A1/(t1 + x1 *cos(alpha) + y1 * sin(alpha))/2;
        else
            r = A2/(t2 + x2 *cos(alpha) + y2 * sin(alpha))/2;
    }
            
        
    printf("%.6f %.6f\n", r * cos(alpha) + x[i], r * sin(alpha) + y[i]);
}
int main()
{
    for (int dd = 1; ; ++ dd)
    {
        double c;
        cin >> c;
        c/=1000;
        if (abs(c) < 1e-6)
            break;
        scanf("%lf %lf %lf %lf %lf %lf", x, y, x+1, y+1, x+2, y+2);
        scanf("%lf %lf %lf", t, t+1, t+2);
        printf("Case %d:\n", dd);
        t[0] *= c;
        t[1] *= c;
        t[2] *= c;
        if (solve(0, 1, 2))
            continue;        
    }
    return 0;
}
