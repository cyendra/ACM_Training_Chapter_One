#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=211;
const int maxm=21111;
const int INF=0x3f3f3f3f;
const double OO=1e100;
const double eps=1e-6;
struct EdgeNode{
    int to;
    double w;
    double T;
    int next;
};

struct HeapNode{
    int d,u;
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};

struct Dijkstra{
    EdgeNode edges[maxm];
    int head[maxn];
    int edge,n;
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedges(int u,int v,double w,double t){
        edges[edge].w=w,edges[edge].T=t,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    double dis[maxn];
    int pre[maxn];
    bool dijkstra(int s,int t,double c){
        priority_queue<HeapNode>que;
        for (int i=0;i<=n;i++) dis[i]=OO;
        dis[s]=0;
        memset(done,0,sizeof(done));
        que.push((HeapNode){0,s});
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                double w=edges[i].w;
                double tm=edges[i].T;
                if (tm<=c&&dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pre[v]=u;
                    que.push((HeapNode){dis[v],v});
                }
            }
        }
        if (dis[t]<OO) return true;
        return false;
    }
    void output(int s,int t){
        if (s!=t) output(s,pre[t]);
        else{
            printf("%d",s);
            return;
        }
        printf(" %d",t);
    }
}solver;
int n,m;
int s,t;
int main()
{
    while (~scanf("%d%d",&n,&m)){
        double l=OO;
        double r=0;
        scanf("%d%d",&s,&t);
        solver.init(n);
        for (int i=0;i<m;i++){
            int x,y;
            double w,tm;
            scanf("%d%d%lf%lf",&x,&y,&tm,&w);
            solver.addedges(x,y,w,tm);
            solver.addedges(y,x,w,tm);
            l=min(l,tm);
            r=max(r,tm);
        }
        while (r-l>eps){
            double mid=(l+r)/2;
            if (solver.dijkstra(s,t,mid)){
                r=mid;
            }
            else{
                l=mid;
            }
        }
        solver.dijkstra(s,t,r);
        solver.output(s,t);
        printf("\n");
        printf("%0.1f %0.1f\n",solver.dis[t],r);
    }
    return 0;
}
