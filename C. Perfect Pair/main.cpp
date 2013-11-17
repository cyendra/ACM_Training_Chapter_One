#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;
LL a,b,m;
LL ans;
int main()
{
    cin>>a>>b>>m;
    if (a>b) swap(a,b);
    if (b>=m) ans=0;
    else if (b<=0) ans=-1;
    else
    {
        ans=0;
        if (a<0)
        {
            if ((-a)%b==0) ans=-a/b;
            else ans=-a/b+1;
            a+=ans*b;
        }
        while (b<m)
        {
            a=a+b;
            if (a>b) swap(a,b);
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
