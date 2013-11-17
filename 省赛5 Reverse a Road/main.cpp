#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn=1111;
const int maxm=111111;
const int OO=1e9;

struct EDGE
{
    int to;
    int w;
    int next;
}edges[maxm],edges0[maxm];

struct COCO{
    int u;
    int v;
    int w;
}coco[maxm];
int lk;

int node,src,dest,edge;
int head[maxn],dist[maxn];
int head0[maxn],dist0[maxn],edge0;

void prepare(int _node,int _src=0,int _dest=0)
{
    node=_node,src=_src,dest=_dest;
    for (int i=0; i<=node; i++) head[i]=-1,head0[i]=-1;
    edge=0;
    edge0=0;
    lk=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}

void addedge0(int u,int v,int c)
{
    edges0[edge0].w=c,edges0[edge0].to=v,edges0[edge0].next=head0[u],head0[u]=edge0++;
}

bool spfa(int node,int src,int head[],EDGE edges[],int dist[])
{
    int i,l,r,u,v,w;
    bool visit[maxn];
    int q[maxn],outque[maxn];
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    for (int i=0; i<=node; i++) dist[i]=OO;
    r=0;
    q[r++]=src;
    dist[src]=0;
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
            if (dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                if (visit[v]) continue;
                q[r++]=v;
                visit[v]=true;
                if (r>=maxn) r=0;
            }
        }
    }
    return true;
}

void dijkstra(int n,int src,int dist[],int head[],EDGE edges[])
{
    int _min,u,v,w;
    bool visit[maxn]={0};
    for (int i=1;i<=n;i++)
    {
        dist[i]=OO;
    }
    dist[src]=0;
    for (int loop=1; loop<=n; loop++)
    {
        u=0;
        _min=OO;
        for (int i=1; i<=n; i++)
        {
            if (!visit[i]&&dist[i]<_min)
            {
                _min=dist[i];
                u=i;
            }
        }
        if (u==0) return;
        visit[u]=true;
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].to;
            w=edges[i].w;
            if (!visit[v]&&dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
            }
        }
    }
}

int main()
{
    int n,s,t,m;
    while (~scanf("%d",&n))
    {
        scanf("%d%d",&s,&t);
        prepare(n,s,t);
        scanf("%d",&m);
        while (m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v,1);
            addedge0(v,u,1);

            coco[lk].u=u;
            coco[lk].v=v;
            coco[lk++].w=1;
        }
        spfa(n,s,head,edges,dist);
        spfa(n,t,head0,edges0,dist0);

        //dijkstra(n,s,dist,head,edges);
        //dijkstra(n,t,dist0,head0,edges0);

        int _min=dist[t];
        int ans=-1;
        for (int i=0;i<lk;i++)
        {
            int u,v,w;
            u=coco[i].u;
            v=coco[i].v;
            w=coco[i].w;
            if (dist[v]+dist0[u]+w<_min)
            {
                _min=dist[v]+dist0[u]+w;
                ans=i;
            }
        }
        printf("%d %d\n",_min,ans+1);
    }

    return 0;
}
