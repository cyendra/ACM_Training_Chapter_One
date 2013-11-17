#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const int OO=1e9;

struct STREDGE
{
    int x;
    int y;
    double v;
} edge[55000];

int p[1111];
int mapx[1111];
int mapy[1111];

void make_set(int x);
int find_set(int x);
void union_set(int x,int y);

bool cmp(STREDGE a,STREDGE b);

int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(p,0,sizeof(p));
        memset(edge,0,sizeof(edge));
        scanf("%d",&n);
        make_set(n);
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d",&mapx[i],&mapy[i]);
        }
        m=0;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                double d=double(mapy[j]-mapy[i])*double(mapy[j]-mapy[i])+double(mapx[j]-mapx[i])*double(mapx[j]-mapx[i]);
                d=sqrt(d);
                if (d>=10.0&&d<=1000.0)
                {
                    edge[m].x=i;
                    edge[m].y=j;
                    edge[m].v=d*100;
                    m++;
                }
            }
        }
        sort(edge,edge+m,cmp);
        double ans=0;
        for (int i=0; i<m; i++)
        {
            int a=find_set(edge[i].x);
            int b=find_set(edge[i].y);
            if (a!=b)
            {
                union_set(a,b);
                ans+=edge[i].v;
            }
        }
        int dad=0;
        for (int i=1; i<=n; i++)
        {
            if (p[i]==i) dad++;
        }
        if (dad==1)
        {
            printf("%0.1f\n",ans);
        }
        else
        {
            printf("oh!\n");
        }
    }
    return 0;
}

bool cmp(STREDGE a,STREDGE b)
{
    return a.v<b.v;
}

void make_set(int t)
{
    for (int i=1; i<=t; i++) p[i]=i;
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
