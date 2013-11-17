#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//�����
const int maxm=1111111;//�ߵ����������Ϊԭͼ������
const int maxn=2222;//����������

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
        //����¼ԭ·����������

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

int n,m;

int a[1111];
int b[1111];
int c[1111][1111];

int main()
{
    while (~scanf("%d%d",&m,&n))
    {
        prepare(m+n+2,0,m+n+1);
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
            addedge(src,i,a[i],0);
        }
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            addedge(i+m,dest,b[i],0);
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&c[i][j]);
                addedge(i,j+m,OO,c[i][j]);
            }
        }
        printf("%d\n",spfaflow());

        prepare(m+n+2,0,m+n+1);
        for (int i=1;i<=m;i++)
        {
            addedge(src,i,a[i],0);
        }
        for (int i=1;i<=n;i++)
        {
            addedge(i+m,dest,b[i],0);
        }
        for (int i=1;i<=m;i++)
        {
            for (int j=1;j<=n;j++)
            {
                addedge(i,j+m,OO,-c[i][j]);
            }
        }
        printf("%d\n",-spfaflow());
    }
    return 0;
}
