#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int maxn=111;
const double esp=1e-3;

struct Edge{
    int from,to;
    double dist;
};

struct BellmanFord{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool inq[maxn];
    double d[maxn];
    int p[maxn];
    int cnt[maxn];

    void init(int n){
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void addedges(int from,int to,int dist)
    {
        edges.push_back((Edge){from,to,dist});
        m=edges.size();
        G[from].push_back(m-1);
    }

    bool negativeCycle()
    {
        queue<int> que;
        memset(inq,0,sizeof(inq));
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<n;i++){ d[i]=0; inq[i]=true; que.push(i); }
        while (!que.empty()){
            int u=que.front();que.pop();
            inq[u]=false;
            for (int i=0;i<G[u].size();i++){
                Edge& e=edges[G[u][i]];
                if (d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];//p[e.to]=e.from;
                    if (!inq[e.to]){
                        que.push(e.to);
                        inq[e.to]=true;
                        if (++cnt[e.to]>n) return true;
                    }
                }
            }
        }
        return false;
    }
}solver;

bool test(double x)
{
    for (int i=0;i<solver.m;i++)
    {
        solver.edges[i].dist-=x;
    }
    bool ret=solver.negativeCycle();
    for (int i=0;i<solver.m;i++)
    {
        solver.edges[i].dist+=x;
    }
    return ret;
}

int main()
{
    int T;
    int maxr;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        solver.init(n);
        maxr=0;
        while (m--)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;v--;
            maxr=max(maxr,w);
            solver.addedges(u,v,w);
        }
        printf("Case #%d: ",cas);
        if (!test(maxr+1)) printf("No cycle found.\n");
        else
        {
            double l=0,r=maxr;
            while (r-l>esp)
            {
                double mid=l+(r-l)/2;
                if (test(mid)) r=mid;
                else l=mid;
            }
            printf("%0.2lf\n",l);
        }
    }
    return 0;
}
