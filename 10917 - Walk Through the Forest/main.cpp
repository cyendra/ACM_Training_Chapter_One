#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=11111;
const int maxm=11111;
const int INF=1e9;

struct Edge{
    int from,to,dist;
};

struct HeapNode{
    int d,u;
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};

struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool done[maxn];
    int d[maxn];
    int p[maxn];

    void init(int n){
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void addedge(int from,int to,int dist){
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    void dijkstra(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<n;i++) d[i]=INF;
        d[s]=0;
        memset(done,0,sizeof(done));
        que.push((HeapNode){0,s});
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    que.push((HeapNode){d[e.to],e.to});
                }
            }
        }

    }
}solver;

int f[maxn];
bool vis[maxn];
/*
int dfs(int u)
{
    int ret=0,v;
    for (int k=0;k<solver.G[u].size();k++)
    {
        v=solver.edges[solver.G[u][k]].to;
        if (solver.d[v]<solver.d[u])
        {
            if (f[v]) ret+=f[v];
            else
            {
                f[v]=dfs(v);
                ret+=f[v];
            }
        }
    }
    return ret;
}
*/


int dfs(int u)
{
    int ret=0,v;
    if (vis[u]) return f[u];
    for (int k=0;k<solver.G[u].size();k++)
    {
        v=solver.edges[solver.G[u][k]].to;
        if (solver.d[v]<solver.d[u])
        {
            if (dfs(v)) ret+=dfs(v);
        }
    }
    vis[u]=true;
    f[u]=ret;
    return ret;
}

int main()
{
    int n,m;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        scanf("%d",&m);
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        solver.init(n);
        while (m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--;
            b--;
            solver.addedge(a,b,c);
            solver.addedge(b,a,c);
        }
        solver.dijkstra(1);
        f[1]=1;
        vis[1]=true;
        printf("%d\n",dfs(0));
    }
    return 0;
}
