#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double x,y;
double f(double a)
{
    double t;
    //t=8*x^4+7*x^3+2*x^2+3*x+6;
    t=8*pow(a,4)+7*pow(a,3)+2*pow(a,2)+3*a+6-y;
    return t;
}

int main()
{
    double r,l,mid,ans;
    bool ns;
    //double dr,dl,dmid;
    while (cin>>y)
    {
        ans=-1;
        r=100;
        l=0;
        ns=true;
        while (r-l>0.000001)
        {
            mid=(r+l)/2;
            if (abs(f(mid))<0.000001)
            {
                l=r=mid;
                ans=mid;
                ns=false;
                break;
            }
            if (f(mid)*f(l)<=0)
            {
                r=mid;
                ns=false;
            }
            else
            {
                l=mid;
            }
        }
        if (ns) printf("No solution!\n");
        else printf("%0.4f\n",mid);
    }
    return 0;
}
