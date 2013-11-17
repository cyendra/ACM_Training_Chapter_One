#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

const int maxn=24;
const int maxs=1<<24;
const LL MOD=1000000007;

int n,m;
LL a[maxn]={0};
LL sum[maxs]={0};
LL b[maxn]={0};
LL f[maxs]={0};
int main()
{
    //init()
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    cin>>m;
    for (int i=0; i<m; i++) cin>>b[i];
    //prepare()
    sum[0]=0;
    for (int s=1; s<(1<<n); s++)
    {
        int k=__builtin_ctz(s);
        sum[s]=sum[s^(1<<k)]+a[k];
        for (int i=0; i<m; i++)
            if (sum[s]==b[i]) f[s]=-1;
    }
    f[0]=1;
    for (int s=1; s<(1<<n); s++)
    {
        if (f[s]<0) f[s]=0;
        else
        {
            for (int i=0; i<n; i++)
                if (s&(1<<i)) f[s]+=f[s^(1<<i)];
            f[s]%=MOD;
        }
    }
    cout<<f[(1<<n)-1]<<endl;
    return 0;
}
