#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//�����
const int maxm=11111;//�ߵ����������Ϊԭͼ������
const int maxn=999;//����������

int node,src,dest,edge;//node�ڵ�����srcԴ�㣬dest��㣬edge����
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];//head����ͷ��p��¼�������Ͻڵ��Ӧ�ķ���ߣ�dis�������

struct edgenode
{
    int to;//�ߵ�ָ��
    int flow;//�ߵ�����
    int cost;//�ߵķ���
    int next;//�������һ����
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
        //����¼ԭ·����������
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
