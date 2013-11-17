#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=55555;
const int maxm=111111111;
const double OO=1e30;

struct HeapNode
{
    double d;
    int u;
    bool operator<(const HeapNode& rhs) const
    {
        return d<rhs.d;
    }
};

struct EDGENODE
{
    int to;
    int w;
    int next;
}edges[maxm];
int edge,head[maxn];
void addedge(int u,int v,int c)
{
    edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
int n;
double dist[maxn];
bool visit[maxn]= {0};
/*
void dijkstra(int src)
{
    int u,v,w;
    double _max;
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    dist[src]=1;
    for (int loop=1; loop<=n; loop++)
    {
        //cerr<<loop<<endl;
        u=0;
        _max=0.0;
        for (int i=1; i<=n; i++)
        {
            //printf("%0.2lf ",dist[i]);
            if (!visit[i]&&dist[i]>_max)
            {
                _max=dist[i];
                u=i;
            }
        }
        //printf("\n");
        if (u==0) return;
        visit[u]=true;
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].to;
            w=edges[i].w;
            if (!visit[v]&&dist[u]*(1.0-(double)w/100.0)>dist[v])
            {
                dist[v]=dist[u]*(1.0-(double)w/100.0);
            }
        }
    }
}
*/

void dijkstra(int src)
{
    int u,v,w;
    priority_queue<HeapNode>que;
    memset(visit,0,sizeof(visit));
    memset(dist,0,sizeof(dist));
    dist[src]=1;
    que.push((HeapNode){0,src});
    while (!que.empty())
    {
        HeapNode x=que.top();
        que.pop();
        u=x.u;
        if (visit[u]) continue;
        visit[u]=true;
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            v=edges[i].to;
            w=edges[i].w;
            if (dist[u]*(1.0-(double)w/100.0)>dist[v])
            {
                dist[v]=dist[u]*(1.0-(double)w/100.0);
                que.push((HeapNode){dist[v],v});
            }
        }
    }
}



/*
bool spfa(int node,int src,int head[],EDGENODE edges[],double dist[])
{
    int i,l,r,u,v,w;
    bool visit[maxn];
    int q[maxn],outque[maxn];
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    for (int i=0; i<=node; i++) dist[i]=0;
    r=0;
    q[r++]=src;
    dist[src]=1;
    visit[src]=true;
    for (l=0; l!=r; ( (++l>=maxn)?(l=0):(1) ))
    {
        u=q[l];
        visit[u]=false;
        outque[u]++;
        if (outque[u]>node) return false;
        for (i=head[u]; i!=-1; i=edges[i].next)
        {
            v=edges[i].to;
            w=edges[i].w;
            if (dist[u]*(1.0-(double)w/100.0)>dist[v])
            {
                dist[v]=dist[u]*(1.0-(double)w/100.0);
                if (visit[v]) continue;
                q[r++]=v;
                visit[v]=true;
                if (r>=maxn) r=0;
            }
        }
    }
    return true;
}
*/

int main()
{
    int t;
    int src,dest;
    int M;
    //freopen("abc.in","r",stdin);
    //freopen("abc.out","w",stdout);
    while (~scanf("%d",&n))
    {
        init();
        for (int u=1; u<=n; u++)
        {
            scanf("%d",&t);
            while (t--)
            {
                int v,c;
                scanf("%d%d",&v,&c);
                addedge(u,v,c);
            }
        }
        scanf("%d%d%d",&src,&dest,&M);
        dijkstra(src);
        //spfa(n,src,head,edges,dist);
        if (dist[dest]>0.000001) printf("%0.2lf\n",M-dist[dest]*M);
        else printf("IMPOSSIBLE!\n");
    }
    return 0;
}
