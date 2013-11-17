#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=2222;
const int INF=1e9;

int n,h;
struct dwarfs{
    int a;
    int b;
}d[maxn];
int f[maxn][maxn];
int sum[maxn];
int ans;
bool cmp(dwarfs x,dwarfs y)
{
    return (x.a+x.b)>(y.a+y.b);
}

int main()
{
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        sum[0]=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&d[i].a,&d[i].b);
        }
        scanf("%d",&h);
        sort(d+1,d+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            sum[i]=sum[i-1]+d[i].a;
        }
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                f[i][j]=INF;
            }
        }
        f[0][0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=i;j++)
            {
                f[i][j]=f[i-1][j]-d[i].a;
                int tmp;
                if (j>0) tmp=max(f[i-1][j-1],h-sum[i]-d[i].b);
                else tmp=h-sum[i]-d[i].b;
                if (tmp<f[i][j]) f[i][j]=tmp;
                if (f[i][j]<0) f[i][j]=0;
            }
        }
        for (int j=n;j>=0;j--)
        {
            if (f[n][j]<=0)
            {
                ans=j;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
