#include <iostream>
#define OO 9999999

using namespace std;

int n,m,mv,k,t;
int v[200],c[200];
int f[111111];
int g[111111];
int l;

void CompletePack(int v)
{
    for (int i=v;i<=l;i++)
    {
        if (f[i]>f[i-v]+1 ) f[i]=f[i-v]+1;
    }
}

void ZeroOnePack(int v,int d)
{
    for (int i=l;i>=v;i--)
    {
        if (f[i]>f[i-v]+d ) f[i]=f[i-v]+d;
    }
}

int main()
{
    while (cin>>n>>m)
    {
        mv=0;
        for (int i=0;i<n;i++)
        {
            cin>>v[i];
            if (v[i]>mv) mv=v[i];
        }
        l=mv*mv+m;
        for (int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for (int i=0;i<=l;i++)
        {
            f[i]=OO;
            g[i]=OO;
        }
        f[0]=0;
        g[0]=0;
        for (int i=0;i<n;i++)
        {
            if (v[i]*c[i]>=l)
            {
                CompletePack(v[i]);
            }
            else
            {
                k=1;
                t=c[i];
                while (k<t)
                {
                    ZeroOnePack(v[i]*k,k);
                    t-=k;
                    k<<=1;
                }
                ZeroOnePack(v[i]*t,t);
            }
        }
        for (int i=0;i<n;i++)
        {
            for (int j=v[i];j<=l;j++)
            {
                if (g[j]>g[j-v[i]]+1) g[j]=g[j-v[i]]+1;
            }
        }
        for (int i=m;i<=l;i++)
        {
            f[m]=min(f[m] , f[i]+g[i-m]);
        }
        if (f[m]<OO)
        {
            cout<<f[m]<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
