#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int OO=1e9;//无穷大
const int maxm=171111;//边的最大数量，为原图的两倍
const int maxn=999;//点的最大数量

int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
int head[maxn],work[maxn],dis[maxn],q[maxn];//head链表头，work临时表头，dis计算距离

struct edgenode{
    int to;//边的指向
    int flow;//边的容量
    int next;//链表的下一条边
}edges[maxm];

//初始化链表及图的信息
void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0;i<node;i++) head[i]=-1;
    edge=0;
}

//添加一条从u到v容量为c的边
void addedge(int u,int v,int c)
{
    edges[edge].flow=c;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].flow=0;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

//广搜计算出每个点与源点的最短距离，如果不能到达汇点说明算法结束
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
            {//这条边必须要有剩余流量
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
    for (int &i=work[u];i!=-1;i=edges[i].next)
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
        for (int i=0;i<node;i++) work[i]=head[i];
        while ( tmp=Dinic_dfs(src,OO) ) ret+=tmp;
    }
    return ret;
}

vector<string>poly;
vector<string>words;

int ans;

int main()
{
    int T;
    int n,m;
    char templar[1111];
    scanf("%d",&T);
    while (T--)
    {
        poly.clear();
        words.clear();
        ans=0;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",templar);
            poly.push_back(templar);
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%s",templar);
            words.push_back(templar);
        }
        for (int i=0;i<words.size();i++)
        {
            prepare(words[i].length()+n+2,0,words[i].length()+n+1);
            for (int j=0;j<words[i].length();j++)
            {
                addedge(src,j+1,1);
                for (int k=0;k<poly.size();k++)
                {
                    if (poly[k].find(words[i][j])!=string::npos)
                    {
                        addedge(j+1,k+1+words[i].length(),1);
                    }
                }
            }
            for (int k=0;k<poly.size();k++)
            {
                addedge(k+1+words[i].length(),dest,1);
            }
            if (Dinic_flow()==words[i].length()) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
