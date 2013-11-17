#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double a,v,l,d,w,t,t1;

double fun( double a,double b,double c )
{
    double del=b*b-4*a*c;
    if ( del<0 ) return 0;
    return ( -b+sqrt(del) )/(2*a);
}

int main()
{
    cin>>a>>v;
    cin>>l>>d>>w;
    cout<<fixed<<setprecision(12);
    if ( v<=w||( 0.5*w*w>=a*d ) )
    {
        t=v/a;
        if ( 0.5*v*t>=l )
        {
            cout<<sqrt(2*l/a)<<endl;
        }
        else
        {
            t=t+(l-0.5*v*t)/v;
            cout<<t<<endl;
        }
    }
    else
    {
        t=(v-w)/a;
        if ( 0.5*v*v/a+v*t-0.5*a*t*t>=d )
        {
            t=w/a;
            t=t+fun( a,2*w,0.5*a*t*t-d )*2;
        }
        else
        {
            t=v/a+(v-w)/a+( d-(0.5*v*v/a+v*t-0.5*a*t*t) )/v;
        }
        t1=(v-w)/a;
        if ( w*t1+0.5*a*t1*t1+d>=l )
        {
            t=t+fun(0.5*a,w,d-l);
        }
        else
        {
            l=l-(w*t1+0.5*a*t1*t1+d);
            t=t+t1+l/v;
        }
        cout<<t<<endl;
    }
    return 0;
}
