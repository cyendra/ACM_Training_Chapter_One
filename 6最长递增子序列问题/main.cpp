#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;//无穷大
const int maxm=111111;//边的最大数量，为原图的两倍
const int maxn=999;//点的最大数量

int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
int head[maxn],work[maxn],dis[maxn],q[maxn];//head链表头，work临时表头，dis计算距离

struct edgenode
{
    int to;//边的指向
    int flow;//边的容量
    int next;//链表的下一条边
} edges[maxm];

//初始化链表及图的信息
void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++) head[i]=-1;
    edge=0;
}

//添加一条从u到v容量为c的边
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

//广搜计算出每个点与源点的最短距离，如果不能到达汇点说明算法结束
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
                //这条边必须要有剩余流量
                q[r++]=v;
                dis[v]=dis[u]+1;
                if (v==dest) return true;
            }
        }
    }
    return false;
}

//寻找可行流的增广路算法，按节点的距离来找，加快速度
int Dinic_dfs(int u,int exp)
{
    int v,tmp;
    if (u==dest) return exp;
    //work是临时链表头，这里用 i引用它，这样寻找过的边不再寻找
    for (int &i=work[u]; i!=-1; i=edges[i].next)
    {
        v=edges[i].to;
        if (edges[i].flow&&dis[v]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0)
        {
            edges[i].flow-=tmp;
            edges[i^1].flow+=tmp;
            //正反向边容量改变
            return tmp;
        }
    }
    return 0;
}

//求最大流直到没有可行流
int Dinic_flow()
{
    int ret=0,tmp;
    while (Dinic_bfs())
    {
        for (int i=0; i<node; i++) work[i]=head[i];
        while ( tmp=Dinic_dfs(src,OO) ) ret+=tmp;
    }
    return ret;
}

int n,s;
int a[1111];
int f[1111];

int main()
{
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        s=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=1; i<=n; i++)
        {
            f[i]=1;
            for (int j=1; j<i; j++)
            {
                if (f[j]+1>f[i]&&a[j]<a[i])
                {
                    f[i]=f[j]+1;
                }
            }
            if (f[i]>s) s=f[i];
        }
        cout<<s<<endl;

        //for (int i=1;i<=n;i++) cerr<<f[i]<<" ";cerr<<endl;

        prepare(n*2+2,0,n*2+1);
        for (int i=1; i<=n; i++)
        {
            if (f[i]==1) addedge(src,i,1);
            if (f[i]==s) addedge(i+n,dest,1);
            addedge(i,i+n,1);
            for (int j=1; j<i; j++)
            {
                if (f[j]+1==f[i]&&a[i]>a[j]) addedge(j+n,i,1);
            }
        }
        int ans1=Dinic_flow();
        cout<<ans1<<endl;

        prepare(n*2+2,0,n*2+1);
        for (int i=1; i<=n; i++)
        {
            if (i==1||i==n)
            {
                addedge(i,i+n,OO);
                if (f[i]==1) addedge(src,i,OO);
                if (f[i]==s) addedge(i+n,dest,OO);
            }
            else
            {
                addedge(i,i+n,1);
                if (f[i]==1) addedge(src,i,1);
                if (f[i]==s) addedge(i+n,dest,1);
            }
            for (int j=1; j<i; j++)
            {
                if (f[j]+1==f[i]&&a[i]>a[j]) addedge(j+n,i,1);
            }
        }
        int ans2=Dinic_flow();
        if (ans2>OO) cout<<ans1<<endl;
        else cout<<ans2<<endl;
    }
    return 0;
}
