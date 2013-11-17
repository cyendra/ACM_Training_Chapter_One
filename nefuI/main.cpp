#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    long long a,b,j;
    double t1=(sqrt(5)-1)/2;
    double t2=(1+sqrt(5))/2;
    while(cin>>a>>b)
    {
        if(a>b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        j=a*t1;
        if(a==(long long)(j*t2))
        {
            if(b==a+j)
            {
                cout<<0<<endl;
                continue;
            }
        }
        else if(a==(long long)((j+1)*t2))
        {
            if(b==a+j+1)
            {
                cout<<0<<endl;
                continue;
            }
        }
        cout<<1<<endl;
    }
    return 0;
}
