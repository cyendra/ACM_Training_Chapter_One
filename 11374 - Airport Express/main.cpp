#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn=111111;
const int maxm=2222222;
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

int d1[maxn],p1[maxn];
int d2[maxn],p2[maxn];

int n,s,e;
void dfs1(int u)
{
    if (u==s)
    {
        printf("%d",u+1);
        return;
    }
    Edge e=solver.edges[p1[u]];
    dfs1(e.from);
    printf(" %d",u+1);
}

void dfs2(int u)
{
    if (u==e)
    {
        printf(" %d",u+1);
        return;
    }
    printf(" %d",u+1);
    Edge e=solver.edges[p2[u]];
    dfs2(e.from);
}

int main()
{
    int m,x,y,z,k;
    int cnt=0;
    while (~scanf("%d%d%d",&n,&s,&e))
    {
        if (cnt++) puts("");
        s--;e--;
        solver.init(n);
        scanf("%d",&m);
        while (m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            solver.addedge(x,y,z);
            solver.addedge(y,x,z);
        }
        solver.dijkstra(s);
        for (int i=0;i<n;i++)
        {
            d1[i]=solver.d[i];
            p1[i]=solver.p[i];
        }
        solver.dijkstra(e);
        for (int i=0;i<n;i++)
        {
            d2[i]=solver.d[i];
            p2[i]=solver.p[i];
        }

        int ans=d1[e];
        int a=-1,b=-1;
        scanf("%d",&k);
        for (int i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;
            y--;
            if (d1[x]+d2[y]+z<ans)
            {
                ans=d1[x]+d2[y]+z;
                a=x;
                b=y;
            }
            if (d1[y]+d2[x]+z<ans)
            {
                ans=d1[y]+d2[x]+z;
                a=y;
                b=x;
            }
        }
        if (a==-1)
        {
            dfs1(e);
            puts("");
            puts("Ticket Not Used");
            printf("%d\n",ans);
        }
        else
        {
            dfs1(a);
            //dfs1(de,b,e);
            dfs2(b);
            puts("");
            printf("%d\n",a+1);
            printf("%d\n",ans);
        }

    }
    return 0;
}
