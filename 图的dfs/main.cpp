#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;



int main()
{

    return 0;
}


/*=================================*\
|  dfs求无向连通图割顶
|  Init: G[]存无向图的边;vertex:1~n;
|  Call: cut_vertex();
\*=================================*/
/*
const int maxn=1111;
vector<int>G[maxn];
int pre[maxn],low[maxn];
bool iscut[maxn];
int dfs_clock;
int cut_dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    int sz=G[u].size();
    for (int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if (!pre[v])
        {
            child++;
            int lowv=cut_dfs(v,u);
            lowu=min(lowu,lowv);
            if (lowv>=pre[u])
            {
                iscut[u]=true;
            }
        }
        else if (pre[v]<pre[u]&&v!=fa)
        {
            lowu=min(lowu,pre[v]);
        }
    }
    if (fa<0&&child==1) iscut[u]=false;
    low[u]=lowu;
    return lowu;
}
void cut_vertex()
{
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(iscut,0,sizeof(iscut));
    dfs_clock=0;
    cut_dfs(1,-1);
}
*/
/*=================================*\
|  节点u所在的强连通分量是否为二分图
|  Init: G[]存无向图的边;vertex:1~n;
|  Call: bipartite(u);
\*=================================*/
/*
int color[maxn];
bool bipartite(int u)
{
    int sz=G[u].size();
    for (int i=0;i<sz;i++)
    {
        int v=G[u][i];
        if (color[v]==color[u]) return false;
        if (!color[v])
        {
            color[v]=3-color[u];
            if (!bipartite(v)) return false;
        }
    }
    return true;
}

*/
