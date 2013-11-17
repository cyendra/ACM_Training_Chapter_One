#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int OO=1e9;

struct STREDGE{
    int x;
    int y;
    int v;
}edge[5000];

int p[5000];

void make_set(int x);
int find_set(int x);
void union_set(int x,int y);
bool cmp(STREDGE a,STREDGE b)
{
    return a.v<b.v;
}

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


int n,m;

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        m=n*(n-1)/2;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].v);
        }
        sort(edge,edge+m,cmp);
        make_set(n);
        int ans=0;
        for (int i=0;i<m;i++)
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
