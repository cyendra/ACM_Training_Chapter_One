#include <iostream>

using namespace std;
long long quickmod(long long  a, long long  b, long long  m)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%m;
            b--;
        }
        b/=2;
        a=a*a%m;
    }
    return ans;
}

int main()
{
    long long int x,ans;
    while (cin>>x)
    {
        ans=quickmod(x,x,10000);
        if (x<5)
        {
            cout<<ans<<endl;
        }
        else
        {
            if (ans<1000) cout<<0;
            if (ans<100) cout<<0;
            if (ans<10) cout<<0;
            cout<<ans<<endl;
        }
    }
    return 0;
}
