#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double f[16][512],p[512][512];
int e[16];
int n;

int main()
{
    memset(e,0,sizeof(e));
    memset(a,0,sizeof(a));
    e[0]=1;
    for (int i=1; i<=7; i++) e[i]=e[i-1]*2;
    //---nice---
    while (~scanf("%d",&n))
    {
        if (n==-1) break;
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        for (int i=1; i<=e[n]; i++)
        {
            for (int j=1; j<=e[n]; j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }
        for (int i=1;i<=e[n];i++) f[0][i]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=e[n];j++)
            {
                for (int k=1;k<=e[n];k++)
                {
                    if ((((j-1)>>(i-1))^1)==(k-1)>>(i-1))
                        f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
                }
            }
        }
        double mx=0;
        int win=0;
        for (int i=1;i<=e[n];i++)
        {
            if (f[n][i]>mx)
            {
                mx=f[n][i];
                win=i;
            }
        }
        printf("%d\n",win);
    }
    return 0;
}

/*
    for (int i=1; i<=7; i++)
        for (int j=1; j<=e[7]; j++)
            for (int k=1; k<=e[7]; k++)
            {
                if (a[i][j].x==0&&((j-1)>>i)==((k-1)>>i)) a[i][j].x=k;
                if (((j-1)>>i)==((k-1)>>i)) a[i][j].y=k;
            }
    for (int i=1;i<=e[7];i++)
    {
        a[0][i].x=i;
        a[0][i].y=i;
    }
*/


/*
//ac v1
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct WRYY
{
    int x;
    int y;
} a[16][512];
double f[16][512],p[512][512];
int e[16];
int n;

int main()
{
    memset(e,0,sizeof(e));
    memset(a,0,sizeof(a));
    e[0]=1;
    for (int i=1; i<=7; i++) e[i]=e[i-1]*2;
    //---nice---
    while (~scanf("%d",&n))
    {
        if (n==-1) break;
        memset(f,0,sizeof(f));
        memset(p,0,sizeof(p));
        for (int i=0; i<e[n]; i++)
        {
            for (int j=0; j<e[n]; j++)
            {
                scanf("%lf",&p[i][j]);
            }
        }
        for (int i=0;i<e[n];i++) f[0][i]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<e[n];j++)
            {
                for (int k=0;k<e[n];k++)
                {
                    if (((j>>(i-1))^1)==k>>(i-1))
                    f[i][j]+=f[i-1][j]*f[i-1][k]*p[j][k];
                }
            }
        }
        double mx=0;
        int win=0;
        for (int i=0;i<e[n];i++)
        {
            if (f[n][i]>mx)
            {
                mx=f[n][i];
                win=i;
            }
        }
        printf("%d\n",win+1);
    }
    return 0;
}
*/
