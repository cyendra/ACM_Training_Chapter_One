#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;
const int maxn=1111;
const int maxm=111111;

struct EDGE{
    int to;
    int flow;
    int next;
}edges[maxm];

int node,edge,src,dest;
int head[maxn],dis[maxn],work[maxn],q[maxn];
void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int c);
int Dinic_flow();
bool Dinic_bfs();
int Dinic_dfs(int u,int exp);

void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0;i<node;i++) head[i]=-1;
    edge=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].flow=c;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].flow=0;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

int Dinic_flow()
{
    int ret=0,tmp;
    while (Dinic_bfs())
    {
        for (int i=0;i<node;i++) work[i]=head[i];
        while (tmp=Dinic_dfs(src,OO)) ret+=tmp;
    }
    return ret;
}

bool Dinic_bfs()
{
    int u,v,r=0;
    for (int i=0;i<node;i++) dis[i]=-1;
    q[r++]=src;
    dis[src]=0;
    for (int l=0;l<r;l++)
    {
        u=q[l];
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].to;
            if (edges[i].flow&&dis[v]<0)
            {
                q[r++]=v;
                dis[v]=dis[u]+1;
                if (v==dest) return true;
            }
        }
    }
    return false;
}

int Dinic_dfs(int u,int exp)
{
    int v,tmp;
    if (u==dest) return exp;
    for (int &i=work[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].to;
        if (edges[i].flow&&dis[v]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0)
        {
            edges[i].flow-=tmp;
            edges[i^1].flow+=tmp;
            return tmp;
        }
    }
    return 0;
}

int main()
{
    int n,m,total,maxflow;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        prepare(m+n+2,0,m+n+1);
        total=0;
        for (int i=1;i<=m;i++)
        {
            int t,k,v;
            scanf("%d%d",&t,&k);
            addedge(src,i,t);
            total+=t;
            while (k--)
            {
                scanf("%d",&v);
                addedge(i,m+v,OO);
            }
        }
        for (int i=m+1;i<=m+n;i++)
        {
            int t;
            scanf("%d",&t);
            addedge(i,dest,t);
        }
        //cerr<<"read-over"<<endl;
        maxflow=Dinic_flow();
        //cerr<<"maxflow---"<<maxflow<<endl;
        printf("%d\n",total-maxflow);
    }
    return 0;
}
