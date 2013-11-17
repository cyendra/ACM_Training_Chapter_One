#include <iostream>
#include <cstdio>
#define OO 9999999
using namespace std;

int m,k;
int v[]={1,5,10,25};
int c[5];
int f[11111];
int p[11111];
int t[11111];
int ans[5];

void CompletePack(int u,int k);
void ZeroOnePack(int u,int d,int k);

void CompletePack(int u,int k)
{
    for (int i=u;i<=m;i++)
    {
        if ( f[i-u]>=0 && f[i]<f[i-u]+1 )
        {
            f[i]=f[i-u]+1;
            p[i]=i-u;
            t[i]=k;
        }
    }
}

void ZeroOnePack(int u,int d,int k)
{
    for (int i=m;i>=u;i--)
    {
        if ( f[i-u]>=0 && f[i]<f[i-u]+d )
        {
            f[i]=f[i-u]+d;
            p[i]=i-u;
            t[i]=k;
        }
    }
}

int main()
{
    while (scanf("%d%d%d%d%d",&m,&c[0],&c[1],&c[2],&c[3])!=EOF)
    {
        if (!(m+c[0]+c[1]+c[2]+c[3])) break;
        for (int i=0;i<=m;i++)
        {
            f[i]=-1;
            p[i]=0;
            t[i]=0;
        }
        f[0]=0;
        for (int i=0;i<4;i++)
        {
            if (c[i]*v[i]>=m)
            {
                CompletePack(v[i],i);
            }
            else
            {
                k=1;
                while (k<c[i])
                {
                    ZeroOnePack(v[i]*k,k,i);
                    c[i]-=k;
                    k<<=1;
                }
                ZeroOnePack(v[i]*c[i],c[i],i);
            }
        }
        if (f[m]>=0)
        {
            for (int i=0;i<4;i++) ans[i]=0;
            while (m)
            {
                ans[ t[m] ]+=(m-p[m])/v[ t[m] ];
                m=p[m];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[0],ans[1],ans[2],ans[3]);
        }
        else
        {
            printf("Charlie cannot buy coffee.\n");
        }
    }
    return 0;
}
