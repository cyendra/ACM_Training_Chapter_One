#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1111;

int m,t,n;

double p[maxn][44];
double f[maxn][44][44];

int main()
{
    while (~scanf("%d%d%d",&m,&t,&n))
    {
        if (m==0&&t==0&&n==0) break;
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        for (int i=1;i<=t;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }
        for (int i=1;i<=t;i++)
        {
            f[i][0][0]=1;
            for (int j=1;j<=m;j++)
            {
                for (int k=0;k<=j;k++)
                {
                    if (k==0)
                    {
                        f[i][j][k]=f[i][j-1][k]*(1-p[i][j]);
                    }
                    else
                    {
                        f[i][j][k]=f[i][j-1][k]*(1-p[i][j])+f[i][j-1][k-1]*p[i][j];
                    }
                }
            }
        }
        double ans=1,sum=0,ans2=1;
        for (int i=1;i<=t;i++)
        {
            sum=0;
            for (int j=1;j<=m;j++)
            {
                sum+=f[i][m][j];
            }
            ans*=sum;
        }
        for (int i=1;i<=t;i++)
        {
            sum=0;
            for (int j=1;j<n;j++)
            {
                sum+=f[i][m][j];
            }
            ans2*=sum;
        }
        ans-=ans2;
        printf("%0.3lf\n",ans);
    }
    return 0;
}
