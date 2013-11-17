#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int f[101][1001];
    int v[101],w[101];
    int t,m;
    while (scanf("%d%d",&t,&m))
    {
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&w[i],&v[i]);
        }
        memset(f,0,sizeof(f));
        for (int i=1;i<=m;i++)
        {
            for (int j=0;j<=t;j++)
            {
                if (t-w[i]>=0)
                {
                    f[i][j]=f[i-1][t-w[i]]+v[i];
                }
                if (f[i][j]<f[i-1][j])
                {
                    f[i][j]=f[i-1][j];
                }
            }
        }
        printf("%d\n",f[m][t]);
    }
    return 0;
}
