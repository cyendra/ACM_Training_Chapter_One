#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;//�����
const int maxm=111111;//�ߵ����������Ϊԭͼ������
const int maxn=1111;//����������

int node,src,dest,edge;//node�ڵ�����srcԴ�㣬dest��㣬edge����
int head[maxn],work[maxn],dis[maxn],q[maxn];//head����ͷ��work��ʱ��ͷ��dis�������
const int direct[4][2]= { {0,1},{1,0},{-1,0},{0,-1} };
int n,m,cnt;

struct edgenode
{
    int to;//�ߵ�ָ��
    int flow;//�ߵ�����
    int next;//�������һ����
} edges[maxm];

//��ʼ������ͼ����Ϣ
void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++) head[i]=-1;
    edge=0;
}

//���һ����u��v����Ϊc�ı�
void addedge(int u,int v,int c)
{
    edges[edge].flow=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

//���Ѽ����ÿ������Դ�����̾��룬������ܵ�����˵���㷨����
bool Dinic_bfs()
{
    int u,v,r=0;
    for (int i=0; i<node; i++) dis[i]=-1;
    q[r++]=src;
    dis[src]=0;
    for (int l=0; l<r; l++)
    {
        u=q[l];
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            v=edges[i].to;
            if (edges[i].flow&&dis[v]<0)
            {
                //�����߱���Ҫ��ʣ������
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
    for (int &i=work[u]; i!=-1; i=edges[i].next)
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
        for (int i=0; i<node; i++) work[i]=head[i];
        while ( (tmp=Dinic_dfs(src,OO))!=0 ) ret+=tmp;
    }
    return ret;
}

struct MAP
{
    int value;
    int index;
    int col;
} a[111][111];

bool check(int x,int y)
{
    if (x>=1&&x<=m&&y>=1&&y<=n) return true;
    else return false;
}

int main()
{
    int maxflow,total,ans,clr;
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        cnt=0;
        total=0;
        maxflow=0;
        clr=0;
        memset(a,0,sizeof(a));
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j].value);
                total+=a[i][j].value;
                if ((i+j)%2==0) a[i][j].col=0;
                else a[i][j].col=1;
                a[i][j].index=++cnt;
            }
        }
        prepare(cnt+2,0,cnt+1);
        for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++)
            {
                int u,c,v;
                u=a[i][j].index;
                c=a[i][j].col;
                v=a[i][j].value;
                if (c==0)
                {
                    addedge(src,u,v);
                    for (int k=0; k<4; k++)
                    {
                        int x,y;
                        x=i+direct[k][0];
                        y=j+direct[k][1];
                        if (check(x,y))
                        {
                            int ind=a[x][y].index;
                            addedge(u,ind,OO);
                        }
                    }
                }
                else if (c==1)
                {
                    addedge(u,dest,v);
                }
            }
        }
        maxflow=Dinic_flow();
        ans=total-maxflow;
        printf("%d\n",ans);
    }
    return 0;
}

