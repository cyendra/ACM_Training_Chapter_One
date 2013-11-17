#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//无穷大
const int maxm=1111111;//边的最大数量，为原图的两倍
const int maxn=2222;//点的最大数量

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

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++)
    {
        head[i]=-1;
        vis[i]=false;
    }
    edge=0;
}

void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=f;
    edges[edge].cost=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for (i=0; i<node; i++) dis[i]=OO;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for (l=0; l!=r; ((++l>=maxn)?l=0:1))
    {
        for (i=head[u=q[l]],vis[u]=false; i!=-1; i=edges[i].next)
        {
            if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if (vis[v]) continue;
                vis[q[r++]=v]=true;
                if (r>=maxn) r=0;
            }
        }
    }
    return p[dest]>=0;
}

int spfaflow()
{
    int i,ret=0,delta;
    while (spfa())
    {
        //按记录原路返回求流量

        for (i=p[dest],delta=OO; i>=0; i=p[edges[i].to])
        {
            delta=min(delta,edges[i^1].flow);
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
    int a,b,n,m,c,u,v;
    while (~scanf("%d%d",&a,&b))
    {
        scanf("%d%d",&n,&m);
        n++;m++;
        prepare(n*m+2,0,n*m+1);
        for (int i=0;i<n;i++)
        {
            for (int j=1;j<m;j++)
            {
                scanf("%d",&c);
                u=i*m+j;
                v=u+1;
                addedge(u,v,1,-c);
                addedge(u,v,OO,0);
            }
        }
        for (int j=1;j<=m;j++)
        {
            for (int i=0;i<n-1;i++)
            {
                scanf("%d",&c);
                u=i*m+j;
                v=u+m;
                addedge(u,v,1,-c);
                addedge(u,v,OO,0);
            }
        }
        int i,j;
        while (a--)
        {
            scanf("%d%d%d",&c,&i,&j);
            addedge(src,i*m+j+1,c,0);
        }
        while (b--)
        {
            scanf("%d%d%d",&c,&i,&j);
            addedge(i*m+j+1,dest,c,0);
        }
        printf("%d\n",-spfaflow());
    }
    return 0;
}
