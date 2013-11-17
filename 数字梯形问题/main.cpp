#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//�����
const int maxm=1111111;//�ߵ����������Ϊԭͼ������
const int maxn=11111;//����������

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

int map[100][100];
int cod[100][100];

int main()
{
    int n,m;
    int cnt;
    while (~scanf("%d%d",&m,&n))
    {
        cnt=0;
        for (int i=1; i<=n+1; i++)
        {
            for (int j=1; j<=m+i-1; j++)
            {
                cnt++;
                if (i<=n) scanf("%d",&map[i][j]);
                else map[i][j]=0;
                cod[i][j]=cnt;
            }
        }
        int num=m*n+(n*n-n)/2;

        //one
        prepare((m*n+(n*n-n)/2)*2+2,0,(m*n+(n*n-n)/2)*2+1);
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m+i-1; j++)
            {
                addedge(cod[i][j],cod[i][j]+num,-map[i][j],1);
                if (i==1)
                {
                    addedge(src,cod[i][j],0,1);
                }
                if (i<n)
                {
                    addedge(cod[i][j]+num,cod[i+1][j],0,1);
                    addedge(cod[i][j]+num,cod[i+1][j+1],0,1);
                }
                else
                {
                    addedge(cod[i][j]+num,dest,0,1);
                }
            }
        }
        int ans=-spfaflow();
        printf("%d\n",ans);

        //two
        prepare(num+2+m+n,0,num+1);
        for (int i=1;i<=n+1;i++)
        {
            for (int j=1;j<=m+i-1;j++)
            {
                if (i==1) addedge(src,cod[i][j],0,1);
                if (i<=n)
                {
                    addedge(cod[i][j],cod[i+1][j],-map[i][j],1);
                    addedge(cod[i][j],cod[i+1][j+1],-map[i][j],1);
                }
                if (i==n+1)
                {
                    addedge(cod[i][j],dest,0,OO);
                }
            }
        }
        ans=-spfaflow();
        printf("%d\n",ans);

        //three
        prepare(num+2+m+n,0,num+1);
        for (int i=1;i<=n+1;i++)
        {
            for (int j=1;j<=m+i-1;j++)
            {
                if (i==1) addedge(src,cod[i][j],0,1);
                if (i<=n)
                {
                    addedge(cod[i][j],cod[i+1][j],-map[i][j],OO);
                    addedge(cod[i][j],cod[i+1][j+1],-map[i][j],OO);
                }
                if (i==n+1)
                {
                    addedge(cod[i][j],dest,0,OO);
                }
            }
        }
        ans=-spfaflow();
        printf("%d\n",ans);
    }
    return 0;
}
