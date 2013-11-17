#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=111;
const int INF=1e9;

int n;
int a[maxn];
int f[maxn][maxn];
bool v[maxn][maxn];
int sum[maxn];

int dp(int l,int r)
{
    int ret=0;
    if (v[l][r]) return f[l][r];
    for (int k=l+1;k<=r;k++) ret=min(ret,dp(k,r));
    for (int k=l;k<=r-1;k++) ret=min(ret,dp(l,k));
    ret=sum[r]-sum[l-1]-ret;
    f[l][r]=ret;
    v[l][r]=true;
    return ret;
}

int main()
{
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        memset(v,0,sizeof(v));
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int ans=dp(1,n);
        printf("%d\n",ans*2-sum[n]);
    }
    return 0;
}
