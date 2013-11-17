#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{

    int t,s,d,n,min;
    int x,y,time;
    int a[1001][1001];
    int f[1001];
    bool v[1001];
    while (scanf("%d%d%d",&t,&s,&d))
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        n=0;
        for (int i=0;i<=1000;i++)
            for (int j=0;j<=1000;j++)
            {
                a[i][j]=-1;
            }
        for (int i=1;i<=t;i++)
        {
            scanf("%d%d%d",&x,&y,&time);
            if (x>n)n=x;
            if (y>n)n=y;
            if (a[x][y]==-1)
            {
                a[x][y]=time;
                a[y][x]=time;
            }
            else if (time<a[x][y])
            {
                a[x][y]=time;
                a[y][x]=time;
            }
        }
        for (int i=1;i<=s;i++)
        {
            scanf("%d",&x);
            a[0][x]=0;
            a[x][0]=0;
        }
        v[0]=true;
        min=65535;
        bool ok=true;
        while (ok)
        {
            for (int i=0;i<=n;i++)
            {
                if (v[i]==true)
                {
                    for (int k=0;k<=n;k++)
                    {
                        if ( (v[k]==false)and(a[i][k]!=-1) )
                        {
                            if (f[k]==0)
                            {
                                f[k]=f[i]+a[i][k];
                                ok=false;
                            }
                            if (f[k]>f[i]+a[i][k])
                            {
                                f[k]=f[i]+a[i][k];
                                ok=false;
                            }
                        }
                    }
                }
            }
        }
        for (int i=1;i<=d;i++)
        {
            scanf("%d",&x);
            if (f[x]<min)
            {
                min=f[x];
            }
        }
        printf("%d",min);

    }
    return 0;
}
