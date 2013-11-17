#include <iostream>
#include <cmath>

using namespace std;

double ab(double x)
{
    if (x<0) return -x;
    else return x;
}

int main()
{
    int x,y,n,a,b,c,d;
    double p,m,t;
    cin>>x>>y>>n;
    m=9999999999.0;
    p=double(x)/double(y);
    for (int j=1;j<=n;j++)
    {
        t=double(j)*double(x)/double(y);
        c=int(t);
        for (int i=-1;i<=1;i++)
        {
            if ( ab( double(c+i)/double(j)-p ) < ab(m-p) )
            {
                m=double(c+i)/double(j);
                a=c+i;
                b=j;
            }
        }
    }
    cout<<a<<"/"<<b<<endl;
    return 0;
}
