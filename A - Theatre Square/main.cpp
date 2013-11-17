#include <iostream>

using namespace std;

int main()
{
    long long int m,n,a,x,y,ans;
    cin>>n>>m>>a;
    if (m%a==0)
    {
        x=0;
    }
    else
    {
        x=1;
    }
    if (n%a==0)
    {
        y=0;
    }
    else
    {
        y=1;
    }
    x+=m/a;
    y+=n/a;
    ans=x*y;
    cout<<ans<<endl;
    return 0;
}
