#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=222;
const int maxm=11111;

struct EDGENODE{
    int to;
    int next;
}edges[maxm];
int head[maxn];
int edge;

void graph_init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}

void addedge(int u,int v)
{
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}

/*=================================*\
|  节点u所在的强连通分量是否为二分图
|  Call: bipartite(u);
\*=================================*/
int color[maxn];
bool bipartite(int u)
{
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        int v=edges[i].to;
        if (color[v]&&color[v]==color[u]) return false;
        if (!color[v])
        {
            color[v]=3-color[u];
            if (!bipartite(v)) return false;
        }
    }
    return true;
}



int main()
{
    int n,m;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        scanf("%d",&m);
        graph_init();
        while (m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y);
        }
        memset(color,0,sizeof(color));
        if (bipartite(0)) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }
    return 0;
}
