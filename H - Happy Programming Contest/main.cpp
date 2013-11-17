#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T,m,n,t;

struct PRB{
    int w;
    int v;
}a[111];

int f[1111];

struct SPS
{
    int ac;
    int time;
} p[1111];

bool cmp(PRB a,PRB b)
{
    return a.w<b.w;
}

int main()
{
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(f,-1,sizeof(f));
        memset(p,0,sizeof(p));
        cin>>m>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i].w;
        }
        for (int i=1; i<=n; i++)
        {
            cin>>a[i].v;
        }
        sort(a+1,a+1+n,cmp);
        f[0]=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=m; j>=a[i].w; j--)
            {
                if ( f[j-a[i].w]!=-1 )
                {
                    if ( f[j-a[i].w]+a[i].v>f[j] )
                    {
                        f[j]=f[j-a[i].w]+a[i].v;
                        p[j].ac=p[j-a[i].w].ac+1;
                        p[j].time=p[j-a[i].w].time+j;
                    }
                    else if ( f[j-a[i].w]+a[i].v==f[j] )
                    {
                        if ( p[j-a[i].w].ac+1>p[j].ac )
                        {
                            f[j]=f[j-a[i].w]+a[i].v;
                            p[j].ac=p[j-a[i].w].ac+1;
                            p[j].time=p[j-a[i].w].time+j;
                        }
                        else if (p[j-a[i].w].ac+1==p[j].ac && p[j-a[i].w].time+j<p[j].time )
                        {
                            f[j]=f[j-a[i].w]+a[i].v;
                            p[j].ac=p[j-a[i].w].ac+1;
                            p[j].time=p[j-a[i].w].time+j;
                        }
                    }
                }
            }
        }
        int af=0,aac=0,atime=0;
        for (int i=m; i>=0; i--)
        {
            if (f[i]>af)
            {
                af=f[i];
                aac=p[i].ac;
                atime=p[i].time;
            }
            else if (f[i]==af)
            {
                if (p[i].ac>aac)
                {
                    aac=p[i].ac;
                    atime=p[i].time;
                }
                else if (p[i].ac==aac&&p[i].time<atime)
                {
                    aac=p[i].ac;
                    atime=p[i].time;
                }
            }
        }
        /*
        cerr<<"----"<<endl;
        for (int i=0;i<=m;i++)
        {
            cerr<<f[i]<<" "<<p[i].ac<<" "<<p[i].time<<endl;
        }
        cerr<<"----"<<endl;
        */
        cout<<af<<" "<<aac<<" "<<atime<<endl;
    }
    return 0;
}
