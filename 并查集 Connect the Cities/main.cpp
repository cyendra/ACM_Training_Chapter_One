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
    int v;
} edge[550000];

int p[1111];

void make_set(int t);
int find_set(int x);
void union_set(int x,int y);

bool cmp(STREDGE a,STREDGE b);

int n,m,k;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(p,0,sizeof(p));
        make_set(n);
        for (int i=0; i<m; i++)
        {
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].v);
        }
        for (int i=0; i<k; i++)
        {
            int t;
            int q,p;
            scanf("%d",&t);
            if (t)
            {
                scanf("%d",&p);
                p=find_set(p);
                for (int j=1; j<t; j++)
                {
                    scanf("%d",&q);
                    union_set(p,q);
                }
            }
        }
        sort(edge,edge+m,cmp);
        int ans=0;
        for (int i=0; i<m; i++)
        {
            int a=find_set(edge[i].x);
            int b=find_set(edge[i].y);
            if (a^b)
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
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
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
    if ( p[x]^x ) p[x]=find_set(p[x]);
    return p[x];
}

void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    p[y]=x;
}
