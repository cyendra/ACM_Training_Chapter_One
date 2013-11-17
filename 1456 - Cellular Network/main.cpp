#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=111;
const double OO=1e30;

int n,w;
int u[maxn];
int sumu;
double sump[maxn];
double f[maxn][maxn];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        sumu=0;
        sump[0]=0;
        scanf("%d%d",&n,&w);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&u[i]);
            sumu+=u[i];
        }
        sort(u+1,u+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            sump[i]=sump[i-1]+(double)u[i]/sumu;
        }
        for (int i=1;i<=n;i++)
        {
            f[i][1]=sump[i]*i;
            for (int j=2;j<=i&&j<=w;j++)
            {
                f[i][j]=OO;
                for (int k=j-1;k<=i-1;k++)
                {
                    f[i][j]=min(f[i][j],f[k][j-1]+(sump[i]-sump[k])*i);
                }
            }
        }
        printf("%0.4lf\n",f[n][w]);
    }
    return 0;
}
