#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn=3111;
const int INF=1e9;

struct EDGENODE
{
    int to,next;
} edges[maxn];
int head[maxn],edge;
void addedge(int u,int v)
{
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}
void init_edges()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
int n;
int f[maxn][2];
void dp(int u,int pa)
{
    f[u][0]=1;
    f[u][1]=0;
    for (int k=head[u]; k!=-1; k=edges[k].next)
    {
        int v=edges[k].to;
        if (v==pa) continue;
        dp(v,u);
        f[u][0]+=min(f[v][0],f[v][1]);
        f[u][1]+=f[v][0];
    }
}

int main()
{
    while (~scanf("%d",&n))
    {
        int u,v,t;
        init_edges();
        for (int i=0; i<n; i++)
        {
            scanf("%d:(%d)",&u,&t);
            while (t--)
            {
                scanf("%d",&v);
                addedge(u,v);
            }
        }
        dp(0,-1);
        printf("%d\n",min(f[0][0],f[0][1]));
    }
    return 0;
}
