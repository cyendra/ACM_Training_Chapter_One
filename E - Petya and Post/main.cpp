#include <iostream>
#include <cstdio>
using namespace std;

const int maxn=111111;
const int OO=1e9;

int gas[maxn],dis[maxn];
bool v[maxn];
int n,Dk,sum,ans;

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&gas[i]);
    for(int i=0;i<n;i++) scanf("%d",&dis[i]);

    Dk=OO;
    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=gas[i]-dis[i];
        Dk=min(Dk,sum);
    }

    ans=0;
    for(int i=0;i<n;i++)
    {
        if(Dk>=0 && !v[i])
        {
            v[i] = true;
            ans++;
        }
        Dk-=gas[i]-dis[i];
    }

    Dk=OO;
    sum=0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=gas[i]-dis[(i-1+n)%n];
        Dk=min(Dk,sum);
    }

    for(int i=n-1;i>=0;i--)
    {
        if(Dk >= 0 && !v[i])
        {
            v[i]=true;
            ans++;
        }
        Dk-=gas[i]-dis[(i-1+n)%n];
    }

    printf("%d\n", ans);
    for(int i=0;i<n;i++)
    {
        if(v[i])
        {
            printf("%d ", i+1);
        }
    }
    printf("\n");
    return 0;
}


/*
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int maxn=411111;


int gas[maxn]={0};
int dis[maxn]={0};
int f[maxn]={0};
int g[maxn]={0};
bool flagl[maxn]={0};
bool flagr[maxn]={0};
int n,m;
int ans=0;
int p[maxn]={0};

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>gas[i];
        gas[i+n]=gas[i];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>dis[i];
        dis[i+n]=dis[i];
    }
    m=2*n;

    for (int i=2;i<=m;i++)
    {
        f[i]=gas[i]-dis[i-1];
    }
    f[1]=gas[1]-dis[n];

    for (int i=1;i<=m;i++)
    {
        g[i]=gas[i]-dis[i];
    }

    for (int i=2;i<=m;i++)
    {
        f[i]=min(f[i],f[i-1]+f[i]);
        if (f[i]<0) flagl[i]=true;
        cerr<<f[i]<<" ";
    }
    cerr<<endl;

    for (int i=m-1;i>=1;i--)
    {
        g[i]=min(g[i],g[i+1]+g[i]);
        if (g[i]<0) flagr[i]=true;
        cerr<<g[i]<<" ";
    }
    cerr<<endl;

    for (int i=1;i<=n;i++)
    {
        if ( !flagr[i] || !flagl[i+n] )
        {
            p[ans++]=i;
        }
    }
    cout<<ans<<endl;
    for (int i=0;i<ans;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    return 0;
}
*/
