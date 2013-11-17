#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=111111;
const int maxm=111111;

struct TWO_SAT{
    int n;
    vector<int>G[maxn*2];
    bool mark[maxn*2];
    int S[maxn*2],c;

    bool dfs(int x){
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for (int i=0;i<G[x].size();i++)
            if (!dfs(G[x][i])) return false;
        return true;
    }

    void init(int n){
        this->n=n;
        for (int i=0;i<n*2;i++) G[i].clear();
        memset(mark,0,sizeof(mark));
    }
    // x = xval or y = yval
    void add_clause(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }

    bool solve(){
        for (int i=0;i<n*2;i+=2)
            if (!mark[i]&&!mark[i+1]){
                c=0;
                if (!dfs(i)){
                    while (c>0) mark[S[--c]]=false;
                    if (!dfs(i+1)) return false;
                }
            }
        return true;
    }
}TwoSAT;

int year[maxn];

int main()
{
    int n,m;
    int x,y;
    int avg;
    while (~scanf("%d%d",&n,&m))
    {
        if (n==0&&m==0) break;
        TwoSAT.init(n);
        avg=0;
        for (int i=0; i<n; i++)
        {
            scanf("%d",&year[i]);
            avg+=year[i];
        }
        avg/=n;
        while (m--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            if (x==y) continue;
            if ( (year[x]>=avg)==(year[y]>=avg) )
            {
                TwoSAT.add_clause(x,1,y,1);
                TwoSAT.add_clause(x,0,y,0);
            }
            else
            {
                TwoSAT.add_clause(x,1,y,1);
            }
        }
        if (!TwoSAT.solve())
        {
            puts("No solution.");
        }
        else
        {
            for (int i=0;i<n;i++)
            {
                if (!TwoSAT.mark[i*2])
                {
                    if (year[i]>=avg) puts("A");
                    else puts("B");
                }
                else
                {
                    puts("C");
                }
            }
        }
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=111111;
const int maxm=111111;

struct EDGE
{
    int to;
    int w;
    int next;
} edges[maxm];

int head[maxn];
int edge,node;

int lowlink[maxn],pre[maxn],sccno[maxn],stk[maxn],top,dfs_clock,scc_cnt;

void prepare(int _node)
{
    node=_node;
    for (int i=0; i<=node; i++) head[i]=-1;
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
    for(i=head[u]; i!=-1; i=edges[i].next)
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
    for(i=0; i<node; i++)
        if(!pre[i]) Tarjan_dfs(i);
}

bool two_sat()
{
    for(int i=0; i<node; i+=2)
        if(sccno[i]==sccno[i^1])return false;
    return true;
}

int year[maxn];

int main()
{
    int n,m;
    int x,y;
    int avg;
    while (~scanf("%d%d",&n,&m))
    {
        if (n==0&&m==0) break;
        avg=0;
        prepare(n*2);
        for (int i=0; i<n; i++)
        {
            scanf("%d",&year[i]);
            avg+=year[i];
        }
        avg/=n;
        while (m--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            if ( (year[x]>=avg)==(year[y]>=avg) )
            {
                addedge(x<<1|1,y<<1);
                addedge(y<<1|1,x<<1);
                addedge(x<<1,y<<1|1);
                addedge(y<<1,x<<1|1);
            }
            else
            {
                addedge(x<<1|1,y<<1);
                addedge(y<<1|1,x<<1);
            }
        }
        Tarjan_find_scc();
        for(int i=0; i<node; i+=2)
        {
            cerr<<sccno[i]<<" ";
        }
        cerr<<endl;
        if (two_sat())
        {
            ;
        }
        else
        {
            puts("No solution.");
        }
    }
    return 0;
}

*/
