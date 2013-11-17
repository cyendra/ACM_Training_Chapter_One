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
} edge[55000];

int p[1111];

void make_set(int n);
int find_set(int x);
void union_set(int x,int y);

bool cmp(STREDGE a,STREDGE b);

int n,m;

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        memset(p,0,sizeof(p));
        memset(edge,0,sizeof(edge));
        make_set(n);
        m=0;
        for (int i=1; i<=n*(n-1)/2; i++)
        {
            int x,y,v,b;
            scanf("%d%d%d%d",&x,&y,&v,&b);
            if (b==1)
            {
                union_set(x,y);
            }
            else if (b==0)
            {
                edge[m].x=x;
                edge[m].y=y;
                edge[m].v=v;
                m++;
            }
        }
        sort(edge,edge+m,cmp);
        int ans=0;
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
        printf("%d\n",ans);
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
