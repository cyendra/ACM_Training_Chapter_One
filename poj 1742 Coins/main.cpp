#include <iostream>
#include <cstdio>
#define OO 99999999
using namespace std;

int n,m,k;
int a[200];
int c[200];
bool f[111111];
int ans;

void ZeroOnePack(int v)
{
    for (int i=m-v; i>=0; i--)
    {
        if (f[i]) f[i+v]=1;
    }
}

void CompletePack(int v)
{
    for (int i=0; i<=m-v; i++)
    {
        if (f[i]) f[i+v]=1;
    }
}

int main()
{
    //while (cin>>n>>m)
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        for (int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for (int i=0; i<n; i++)
        {
            cin>>c[i];
        }
        for (int i=0; i<=m; i++)
        {
            f[i]=0;
        }
        f[0]=1;
        for (int i=0; i<n; i++)
        {
            if (a[i]*c[i]>=m)
            {
                CompletePack(a[i]);
            }
            else
            {
                k=1;
                while (k<c[i])
                {
                    ZeroOnePack(a[i]*k);
                    c[i]-=k;
                    k<<=1;
                }
                ZeroOnePack(a[i]*c[i]);
            }
        }
        ans=0;
        for (int i=1; i<=m; i++)
        {
            if (f[i]) ans++;
        }
        //cout<<ans<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
