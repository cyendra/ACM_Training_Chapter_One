#include <iostream>

using namespace std;

const int OO=1e9;//�����
const int maxm=111111;//�ߵ����������Ϊԭͼ������
const int maxn=999;//����������

int node,src,dest,edge;//node�ڵ�����srcԴ�㣬dest��㣬edge����
int head[maxn],work[maxn],dis[maxn],q[maxn];//head����ͷ��work��ʱ��ͷ��dis�������

struct edgenode{
    int to;//�ߵ�ָ��
    int flow;//�ߵ�����
    int next;//�������һ����
}edges[maxm];

//��ʼ������ͼ����Ϣ
void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0;i<node;i++) head[i]=-1;
    edge=0;
}

//���һ����u��v����Ϊc�ı�
void addedge(int u,int v,int c)
{
    edges[edge].flow=c;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].flow=0;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

//���Ѽ����ÿ������Դ�����̾��룬������ܵ�����˵���㷨����
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
            {//�����߱���Ҫ��ʣ������
                q[r++]=v;
                dis[v]=dis[u]+1;
                if (v==dest) return true;
            }
        }
    }
    return false;
}

//Ѱ�ҿ�����������·�㷨�����ڵ�ľ������ң��ӿ��ٶ�
int Dinic_dfs(int u,int exp)
{
    int v,tmp;
    if (u==dest) return exp;
    //work����ʱ����ͷ�������� i������������Ѱ�ҹ��ı߲���Ѱ��
    for (int &i=work[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].to;
        if (edges[i].flow&&dis[v]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0)
        {
            edges[i].flow-=tmp;
            edges[i^1].flow+=tmp;
            //������������ı�
            return tmp;
        }
    }
    return 0;
}

//�������ֱ��û�п�����
int Dinic_flow()
{
    int ret=0,tmp;
    while (Dinic_bfs())
    {
        for (int i=0;i<node;i++) work[i]=head[i];
        while ( tmp=Dinic_dfs(src,OO) ) ret+=tmp;
    }
    return ret;
}

int main()
{
    int n,m,u,c,v;
    while (cin>>n>>m)
    {
        prepare(m+1,1,m);
        while (n--)
        {
            cin>>u>>v>>c;
            addedge(u,v,c);
        }
        cout<<Dinic_flow()<<endl;
    }
    return 0;
}

