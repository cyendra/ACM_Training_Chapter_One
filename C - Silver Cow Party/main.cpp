#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=11111;
const int maxm=1111111;
const int INF=0x3f3f3f3f;

struct EdgeNode{
    int to;
    int w;
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
    void addedges(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    int dis[maxn];
    int pre[maxn];
    void dijkstra(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<n;i++) dis[i]=INF;
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
                int w=edges[i].w;
                if (dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pre[v]=u;
                    que.push((HeapNode){dis[v],v});
                }
            }
        }
    }
}sol_in,sol_out;

int n,m,x;

int main()
{
    while (~scanf("%d%d%d",&n,&m,&x)){
        sol_in.init(n);
        sol_out.init(n);
        x--;
        for (int i=0;i<m;i++){
            int a,b,t;
            scanf("%d%d%d",&a,&b,&t);
            a--;
            b--;
            sol_in.addedges(a,b,t);
            sol_out.addedges(b,a,t);
        }
        sol_in.dijkstra(x);
        sol_out.dijkstra(x);
        int ans=0;
        //for (int i=0;i<n;i++){
        //    cerr<<sol_in.dis[i]<<" "<<sol_out.dis[i]<<endl;
        //}
        for (int i=0;i<n;i++){
            if (i!=x){
                if (sol_in.dis[i]!=INF&&sol_out.dis[i]!=INF)
                    ans=max(ans,sol_in.dis[i]+sol_out.dis[i]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
