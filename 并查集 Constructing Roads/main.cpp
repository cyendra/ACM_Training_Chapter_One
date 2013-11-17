#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int OO=1e9;

int a[111][111];
int d[111];
bool v[111];
int Q,n;

int main()
{
    while (cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
        cin>>Q;
        for (int i=1;i<=Q;i++)
        {
            int x,y;
            cin>>x>>y;
            a[x][y]=0;
            a[y][x]=0;
        }
        int mind,t,ans;
        ans=0;
        for (int i=1;i<=n;i++) d[i]=OO;
        d[1]=0;
        for (int loop=1;loop<=n;loop++)
        {
            mind=OO;
            for (int i=1;i<=n;i++)
            {
                if (!v[i]&&d[i]<mind)
                {
                    mind=d[i];
                    t=i;
                }
            }
            v[t]=true;
            ans+=mind;
            for (int i=1;i<=n;i++)
            {
                if (a[t][i]<d[i])
                {
                    d[i]=a[t][i];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*

struct EDGE{
    int x;
    int y;
    int v;
};

EDGE edge[10000];

int p[111];
void make_set(int t);
int find_set(int x);
void union_set(int x,int y);

void make_set(int t)
{
    for (int i=1;i<=t;i++) p[i]=i;
}

int find_set(int x)
{
    if ( p[x]==x ) return x;
    else
    {
        int u=find_set(p[x]);
        p[x]=u;
        return u;
    }
}

void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    p[y]=x;
}


*/
