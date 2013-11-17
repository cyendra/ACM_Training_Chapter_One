#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double eps=1e-5;

double f[1111][1111];
double a1[1111][1111],a2[1111][1111],a3[1111][1111];
int n,m;

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%lf%lf%lf",&a1[i][j],&a2[i][j],&a3[i][j]);
            }
        }
        f[n][m]=0;
        for (int i=n;i>=1;i--)
        {
            for (int j=m;j>=1;j--)
            {
                if (i==n&&j==m) continue;
                if (fabs(1-a1[i][j])<eps) continue;
                f[i][j]= ( (f[i][j+1]*a2[i][j]) + (f[i+1][j]*a3[i][j]) + 2 )/(1-a1[i][j]);
            }
        }
        printf("%0.3lf\n",f[1][1]);
    }
    return 0;
}
