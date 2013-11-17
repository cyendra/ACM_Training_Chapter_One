#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn=55000;
const int maxm=250000;
const int INF=0x3f3f3f3f;
typedef long long LL;

struct HeapNode{
    int d,u;
    HeapNode(){}
    HeapNode(int a,int b):d(a),u(b){}
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};
struct EdgeNode{
    int to;
    int w;
    int next;
};
struct Prim{
    EdgeNode edges[maxm];
    int head[maxn];
    int edge,n;
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    int dis[maxn];
    int pre[maxn];
    int dep[maxn];
    void prim(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<=n;i++) dis[i]=INF;
        dis[s]=0;
        memset(done,0,sizeof(done));
        memset(dep,0,sizeof(dep));
        que.push(HeapNode(0,s));
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                int w=edges[i].w;
                if (!done[v]&&dis[v]>w){
                    dis[v]=w;
                    pre[v]=u;
                    dep[v]=dep[u]+1;
                    que.push(HeapNode(dis[v],v));
                }
            }
        }
    }
}solver;
int n,m;
int fa[maxn],cost[maxn],L[maxn];
int anc[maxn][20];
int maxCost[maxn][20];

void preprocess(){
    for (int i=1;i<=n;i++){
        anc[i][0]=fa[i];
        maxCost[i][0]=cost[i];
        for (int j=1;(1<<j)<n;j++) anc[i][j]=-1;
    }
    for (int j=1;(1<<j)<n;j++){
        for (int i=1;i<=n;i++){
            if (anc[i][j-1]!=-1){
                int a=anc[i][j-1];
                anc[i][j]=anc[a][j-1];
                maxCost[i][j]=max(maxCost[i][j-1],maxCost[a][j-1]);
            }
        }
    }
}
int query(int p,int q){
    int log;
    if (L[p]<L[q]) swap(p,q);
    for (log=1;(1<<log)<=L[p];log++);log--;
    int ans=-INF;
    for (int i=log;i>=0;i--){
        if (L[p]-(1<<i)>=L[q]){
            ans=max(ans,maxCost[p][i]);
            p=anc[p][i];
        }
    }
    if (p==q) return ans;
    for (int i=log;i>=0;i--){
        if (anc[p][i]!=-1&&anc[p][i]!=anc[q][i]){
            ans=max(ans,maxCost[p][i]);
            p=anc[p][i];
            ans=max(ans,maxCost[q][i]);
            q=anc[q][i];
        }
    }
    ans=max(ans,cost[p]);
    ans=max(ans,cost[q]);
    return ans;
}

int main()
{
    int cas=0;
    while (~scanf("%d%d",&n,&m)){
        if (cas!=0) puts("");
        cas++;
        solver.init(n);
        for (int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            solver.addedge(x,y,z);
            solver.addedge(y,x,z);
        }
        solver.prim(1);
        for (int i=1;i<=n;i++){
            fa[i]=solver.pre[i];
            cost[i]=solver.dis[i];
            L[i]=solver.dep[i];
        }
        //for (int i=1;i<=n;i++) cerr<<fa[i]<<" ";cerr<<endl;
        preprocess();
        int Q;
        scanf("%d",&Q);
        while (Q--){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y));
        }
    }
    return 0;
}

