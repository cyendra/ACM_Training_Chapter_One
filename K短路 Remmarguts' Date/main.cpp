#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn=1111;
const int maxm=111111;
const int INF=1e9;

struct ANODE
{
    int id;
    int f;
    int g;
    bool operator < (const ANODE &t) const
    {
        if (t.f==f) return t.g<g;
        return t.f<f;
    }
};

struct EDGE
{
    int to;
    int w;
    int next;
}edges[maxm],unti_edges[maxm];

int node,src,dest,edge;
int head[maxn],dist[maxn];

int unti_head[maxn],unti_edge;

void prepare(int _node,int _src=0,int _dest=0)
{
    node=_node,src=_src,dest=_dest;
    for (int i=0; i<=node; i++) head[i]=-1;
    edge=0;
    for (int i=0; i<=node; i++) unti_head[i]=-1;
    unti_edge=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    //edges[edge].w=c,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}

void unti_addedge(int u,int v,int c)
{
    unti_edges[unti_edge].w=c,unti_edges[unti_edge].to=v,unti_edges[unti_edge].next=unti_head[u],unti_head[u]=unti_edge++;
    //unti_edges[unti_edge].w=c,unti_edges[unti_edge].to=u,unti_edges[unti_edge].next=unti_head[v],unti_head[v]=unti_edge++;
}

bool spfa(int node,int src,int head[],EDGE edges[],int dist[])
{
    int i,l,r,u,v,w;
    bool visit[maxn];
    int q[maxn],outque[maxn];
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    for (int i=0; i<=node; i++) dist[i]=INF;
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

int a_star(int start,int end,int n,int k,int head[],EDGE edges[],int dist[])
{
    priority_queue<ANODE> que;
    ANODE u,v;
    int cnt=0;
    if (start==end) k++;
    if (dist[start]==INF) return -1;
    u.id=start;
    u.g=0;
    u.f=u.g+dist[u.id];
    que.push(u);
    while (!que.empty())
    {
        u=que.top();
        que.pop();
        if (u.id==end) cnt++;
        if (cnt==k) return u.g;
        for (int i=head[u.id]; i!=-1; i=edges[i].next)
        {
            v.id=edges[i].to;
            v.g=u.g+edges[i].w;
            v.f=v.g+dist[v.id];
            que.push(v);
        }
    }
    return -1;
}

int main()
{
    int n,m,s,t,k;
    while (~scanf("%d%d",&n,&m))
    {
        prepare(n);
        while (m--)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
            unti_addedge(v,u,c);
        }
        scanf("%d%d%d",&s,&t,&k);
        spfa(node,t,unti_head,unti_edges,dist);
        //spfa(node,t,head,edges,dist);
        int kthlength=a_star(s,t,node,k,head,edges,dist);
        printf("%d\n",kthlength);
    }
    return 0;
}
