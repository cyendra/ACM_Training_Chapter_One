#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=111111;
const long long INF=1e18;

struct POINT{
    int x;
    int y;
}a[maxn];
int x[maxn];
int y[maxn];
long long sumx[maxn];
long long sumy[maxn];
int n;
long long ans;
long long tmp;

int fin(int q[],int key)
{
    int l=1,r=n,m;
    while (l<=r)
    {
        m=(l+r)/2;
        if (q[m]==key) return m;
        if (q[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        sumx[0]=sumy[0]=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            a[i].x=x[i];
            a[i].y=y[i];
        }
        sort(x+1,x+n+1);
        sort(y+1,y+n+1);
        for (int i=1;i<=n;i++)
        {
            sumx[i]=sumx[i-1]+x[i];
            sumy[i]=sumy[i-1]+y[i];
        }
        ans=INF;
        for (int i=1;i<=n;i++)
        {
            int idx=fin(x,a[i].x);
            int idy=fin(y,a[i].y);
            tmp=0;
            tmp+=(1LL*x[idx]*(idx-1)-sumx[idx-1]) + (sumx[n]-sumx[idx]-1LL*x[idx]*(n-idx));
            tmp+=(1LL*y[idy]*(idy-1)-sumy[idy-1]) + (sumy[n]-sumy[idy]-1LL*y[idy]*(n-idy));
            if (tmp<ans) ans=tmp;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

