#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;
const LL MOD=1000000007;

LL quick_mod(LL a,LL b,LL m)
{
    LL ans=1;
    while (b)
    {
        if (b&1)
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
    char s[111111];
    int n,k;
    LL ans,q;
    while (cin>>s>>k)
    {
        ans=0;
        n=strlen(s);
        q=quick_mod(2,n,MOD);
        for (int i=0;i<n;i++)
        {
            if (s[i]=='0'||s[i]=='5')
            {
                ans+=quick_mod(2,i,MOD)%MOD
                *(quick_mod(q,k,MOD)-1+MOD)%MOD
                *quick_mod(q-1,MOD-2,MOD)%MOD;
                ans%=MOD;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
