#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Gib{
    long long m;
    long long t;
};

Gib f[30];
long long g[30];
Gib sum( Gib a,Gib b )
{
    Gib r;
    r.m=a.m+b.m;
    r.t=a.t+b.t;
    return r;
}

int main()
{
    int x,fx,y;
    int T;
    cin>>T;

    while (T--)
    {
        cin>>x>>fx>>y;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        f[0].m=1;
        f[0].t=0;
        f[1].m=0;
        f[1].t=1;
        for (int i=2;i<=x;i++)
        {
            f[i]=sum(f[i-1],f[i-2]);
        }
        g[0]=1;
        if ((fx-f[x].m)%f[x].t!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        g[1]=(fx-f[x].m)/f[x].t;
        if (g[1]<1)
        {
            cout<<-1<<endl;
            continue;
        }
        for (int i=2;i<=y;i++)
        {
            g[i]=g[i-1]+g[i-2];
        }
        cout<<g[y]<<endl;

    }
    return 0;
}
