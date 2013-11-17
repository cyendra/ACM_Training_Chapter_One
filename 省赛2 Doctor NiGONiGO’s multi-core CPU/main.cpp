#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//�����
const int maxm=11111111;//�ߵ����������Ϊԭͼ������
const int maxn=222222;//����������

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

int q_cpu;
int p_jobs;
int cost[222][222];
int T;
int ls;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&q_cpu,&p_jobs);
        ls=p_jobs/q_cpu+1;
        prepare(p_jobs*2+2,0,p_jobs*2+1);
        for (int i=1;i<=p_jobs;i++)
        {
            addedge(src,i,1,0);
            for (int j=1;j<=p_jobs;j++)
            {
                scanf("%d",&cost[i][j]);
                if (j<=ls) addedge(i,j+p_jobs,1,cost[i][j]);
            }
        }
        for (int i=1;i<=p_jobs;i++)
        {
            if (i<=ls) addedge(i+p_jobs,dest,q_cpu,0);
        }
        int ans=spfaflow();
        printf("%d\n",ans);
    }
    return 0;
}
