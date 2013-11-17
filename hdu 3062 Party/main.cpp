#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=4444;
const int maxm=1111111;

struct EDGE{
    int to;
    int w;
    int next;
}edges[maxm];

int head[maxn];
int edge,node;

int lowlink[maxn],pre[maxn],sccno[maxn],stk[maxn],top,dfs_clock,scc_cnt;

void prepare(int _node)
{
    node=_node;
    for (int i=0;i<=node;i++) head[i]=-1;
    edge=0;
}

void addedge(int u,int v,int c=1)
{
    edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}


void Tarjan_dfs(int u)
{
    int i,v;
    pre[u]=lowlink[u]=++dfs_clock;
    stk[top++]=u;
    for(i=head[u];i!=-1;i=edges[i].next)
        if(!pre[v=edges[i].to])
            Tarjan_dfs(v),lowlink[u]=min(lowlink[u],lowlink[v]);
        else if(!sccno[v])
            lowlink[u]=min(lowlink[u],pre[v]);
    if(pre[u]==lowlink[u])
    {
        sccno[u]=++scc_cnt;
        while(stk[--top]!=u)sccno[stk[top]]=scc_cnt;
    }
}

void Tarjan_find_scc()
{
    int i;
    scc_cnt=dfs_clock=top=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(i=0;i<node;i++)
        if(!pre[i]) Tarjan_dfs(i);
}

bool two_sat()
{
    for(int i=0;i<node;i+=2)
        if(sccno[i]==sccno[i^1])return false;
    return true;
}

int main()
{
    int n,m;
    int a1,a2,c1,c2;
    while (~scanf("%d",&n))
    {
        scanf("%d",&m);
        prepare(n+n);
        while (m--)
        {
            scanf("%d%d%d%d",&a1,&a2,&c1,&c2);
            addedge( (a1<<1)+c1, (a2<<1|1)-c2 );
            addedge( (a2<<1)+c2, (a1<<1|1)-c1 );
        }
        Tarjan_find_scc();
        if (two_sat())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

