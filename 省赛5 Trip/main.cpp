#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
const int OO=1e9;
long long a[222][222];
long long f[222][222];

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                a[i][j]=f[i][j]=OO;
            }
        }
        for (int i=1; i<=m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            a[u][v]=a[v][u]=c;
            if(u==1) f[1][v]=c;
            if(v==1) f[1][u]=c;
        }
        long long _min=a[1][n];
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(f[i-1][j]!=OO)
                {
                    for(int k=1; k<=n; k++)
                    {
                        if(f[i-1][j]+i*a[j][k]<f[i][k])
                        {
                            f[i][k]=f[i-1][j]+i*a[j][k];
                        }
                    }
                }
            }
        }
        for(int i=1; i<=n-1; i++)
        {
            if(f[i][n]<_min) _min=f[i][n];
        }
        printf("%I64d\n",_min);
    }
    return 0;
}


