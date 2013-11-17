#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//无穷大
const int maxm=11111;//边的最大数量，为原图的两倍
const int maxn=999;//点的最大数量

int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];//head链表头，p记录可行流上节点对应的反向边，dis计算距离

struct edgenode
{
    int to;//边的指向
    int flow;//边的容量
    int cost;//边的费用
    int next;//链表的下一条边
} edges[maxm];

void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int f,int c);
bool spfa();

void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++)
    {
        head[i]=-1;
        vis[i]=0;
    }
    edge=0;
}

void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=c;
    edges[edge].cost=f;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-f;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

bool spfa()
{
    int u,v,r=0;
    for (int i=0; i<node; i++) dis[i]=OO;
    q[r++]=src;
    dis[src]=0;
    p[src]=p[dest]=-1;
    for (int l=0; l!=r; ((++l>=maxn)?0:l))
    {
        u=q[l];
        vis[u]=0;
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            v=edges[i].to;
            if (edges[i].flow&&dis[v]>dis[u]+edges[i].cost)
            {
                dis[v]=dis[u]+edges[i].cost;
                p[v]=i^1;
                if (!vis[v])
                {
                    q[r++]=v;
                    vis[v]=true;
                    if (r>=maxn) r=0;
                }
            }
        }
    }
    return p[dest]>-1;
}

int spfaflow()
{
    int ret=0,delta;
    while (spfa())
    {
        //按记录原路返回求流量
        delta=OO;
        for (int i=p[dest]; i>=0; i=p[edges[i].to])
        {
            if (edges[i^1].flow<delta) delta=edges[i^1].flow<delta;
        }
        for (int i=p[dest]; i>=0; i=p[edges[i].to])
        {
            edges[i].flow+=delta;
            edges[i^1].flow-=delta;
        }
        ret+=delta*dis[dest];
    }
    return ret;
}

int main()
{
    int n;
    while (~scanf("%d",&n))
    {
        prepare(n+n+2,0,n+n+1);
        for (int i=1; i<=n; i++)
        {
            addedge(src,i,0,1);
            addedge(i+n,dest,0,1);
            for (int j=1; j<=n; j++)
            {
                int f;
                scanf("%d",&f);
                //addedge(i,n+j,f,OO);
                addedge(i,n+j,f,1);
            }
        }
        int ans=spfaflow();
        printf("%d\n",ans);
        for (int i=0;i<edge;i++)
        {
            if ((i&1)==0)
            {
                edges[i].flow+=edges[i^1].flow;
                edges[i^1].flow=0;
                swap(edges[i].cost,edges[i^1].cost);
            }
        }
        ans=spfaflow();
        printf("%d\n",-ans);
    }
    return 0;
}
