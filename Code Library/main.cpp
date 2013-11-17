

/*==============================================*\
 | Code Library
\*==============================================*/
/** head-file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
/** define-for **/
#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define DWN(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_1(i, a, b) for (int i=int(a);i<=int(b);++i)
#define DWN_1(i, b, a) for (int i=int(b);i>=int(a);--i)
#define REP_N(i, n) for (i=0;i<int(n);++i)
#define FOR_N(i, a, b) for (i=int(a);i<int(b);++i)
#define DWN_N(i, b, a) for (i=int(b-1);i>=int(a);--i)
#define REP_1_N(i, n) for (i=1;i<=int(n);++i)
#define FOR_1_N(i, a, b) for (i=int(a);i<=int(b);++i)
#define DWN_1_N(i, b, a) for (i=int(b);i>=int(a);--i)
/** define-useful **/
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) int(x.size())
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x
#define pb push_back
#define mp make_pair
/** test **/
#define Display(A, n, m) {                      \
    REP(i, n){                                  \
        REP(j, m) cout << A[i][j] << " ";       \
        cout << endl;                           \
    }                                           \
}
#define Display_1(A, n, m) {                    \
    REP_1(i, n){                                \
        REP_1(j, m) cout << A[i][j] << " ";     \
        cout << endl;                           \
    }                                           \
}
using namespace std;
/** typedef **/
typedef long long LL;
/** Add - On **/
const int direct4[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
const int direct8[8][2]={ {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
const int direct3[6][3]={ {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };
const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0); //M_PI;
const int maxn=11111;
const int maxm=1111111;
int n,m;
/*==============================================*\
 | 建图
 | INIT: init(int n):void
 | CALL: addedge(int u,int v,int c):void
\*==============================================*/
struct EdgeNode{
    int to;
    int w;
    int next;
};
struct Graph{
    int head[maxn];
    EdgeNode edges[maxm];
    int edge,n;
    void init(int n){
        memset(head,-1,sizeof(head));
        this->n=n;
        edge=0;
    }
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
};
/*==============================================*\
 | Dijkstra+堆优化
 | INIT: init(n);addedge(u,v,c);节点编号0~n
 | CALL: dijkstra(int s);dis[]:最短路;pre[]:前驱
\*==============================================*/
struct HeapNode{
    int d,u;
    HeapNode(){}
    HeapNode(int a,int b):d(a),u(b){}
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
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    int dis[maxn];
    int pre[maxn];
    void dijkstra(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<=n;i++) dis[i]=INF;
        dis[s]=0;
        memset(done,0,sizeof(done));
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
                if (dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pre[v]=u;
                    que.push(HeapNode(dis[v],v));
                }
            }
        }
    }
};
/*==============================================*\
 | BellmanFord+队列优化
 | INIT: init(n);addedge(u,v,c);节点编号0~n
 | CALL: spfa(int s):bool;dist[]:最短路
\*==============================================*/
struct BellmanFord{
    EdgeNode edges[maxm];
    int head[maxn],edge,n;
    bool visit[maxn];
    int outque[maxn];
    queue<int>que;
    int dist[maxn];
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    void init(int n){
        memset(head,-1,sizeof(head));
        edge=0;
        this->n=n;
    }
    bool spfa(int s){
        int top;
        for (int i=0;i<=n;i++) dist[i]=INF;
        memset(visit,0,sizeof(visit));
        memset(outque,0,sizeof(outque));
        while (!que.empty()) que.pop();
        que.push(s);
        visit[s]=true;
        dist[s]=0;
        while (!que.empty()){
            top=que.front();
            que.pop();
            visit[top]=false;
            outque[top]++;
            if (outque[top]>n) return false;
            for (int k=head[top];k!=-1;k=edges[k].next){
                if (dist[edges[k].to]==INF||dist[edges[k].to]>dist[top]+edges[k].w){
                    dist[edges[k].to]=dist[top]+edges[k].w;
                    if (!visit[edges[k].to]){
                        visit[edges[k].to]=true;
                        que.push(edges[k].to);
                    }
                }
            }
        }
        return true;
    }
};
/*==============================================*\
 | 强连通分量-Tarjan
 | INIT: init(n);addedge(u,v);节点编号0~n-1
 | CALL: find_scc();sccno[x]:节点x所属强连通分量
\*==============================================*/
struct Tarjan{
    int head[maxn];
    EdgeNode edges[maxm];
    int edge,n;
    void init(int n){
        memset(head,-1,sizeof(head));
        this->n=n;
        edge=0;
    }
    void addedge(int u,int v,int c=0){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    int pre[maxn],lowlink[maxn],sccno[maxn],scc_cnt,dfs_clock;
    stack<int>stk;
    void dfs(int u){
        pre[u]=lowlink[u]=++dfs_clock;
        stk.push(u);
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            }
            else if (!sccno[v]){
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if (lowlink[u]==pre[u]){
            scc_cnt++;
            int x;
            do{
                x=stk.top();
                stk.pop();
                sccno[x]=scc_cnt;
            }while (x!=u);
        }
    }
    void find_scc(){
        dfs_clock=scc_cnt=0;
        memset(sccno,0,sizeof(sccno));
        memset(pre,0,sizeof(pre));
        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++) if (!pre[i]) dfs(i);
    }
};
/*==============================================*\
 | 点双连通/割点/桥/边双连通
 | INIT: init(n);addedge(u,v);无向图;节点编号1~n
 | CALL: find_bcc():点双连通/割点/桥
 |       find_block():边双连通,先要求出桥
 |       iscut[]:割点;EdgeNode_1.cut:桥
 |       vector<int>bcc[x]:双连通分量x所包含的节点
 |       bccno[x]:节点x所属的点双连通分量,割点的值无意义
 |       block[x]:节点x所属的边双连通分量
\*==============================================*/
struct EdgeNode_1{
    int to;
    int w;
    int next;
    bool cut;
};
struct Edge{
    int u;
    int v;
    Edge(){}
    Edge(int a,int b):u(a),v(b){}
};
struct Bcc_Graph{
    int head[maxn];
    EdgeNode_1 edges[maxm];
    int edge,n;
    void init(int n){
        memset(head,-1,sizeof(head));
        this->n=n;
        edge=0;
    }
    void addedge(int u,int v,int c=0){
        edges[edge].cut=0,edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    //点双连通/割点/桥
    int dfn[maxn],low[maxn],bccno[maxn],dfs_clock,bcc_cnt;
    bool iscut[maxn];
    vector<int>bcc[maxn];
    stack<Edge>stk;
    int dfs(int u,int fa){
        int lowu=dfn[u]=++dfs_clock;
        int child=0;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==fa) continue;
            Edge e=Edge(u,v);
            if (!dfn[v]){
                stk.push(e);
                child++;
                int lowv=dfs(v,u);
                lowu=min(lowu,lowv);
                if (dfn[u]<=lowv){
                    iscut[u]=true;//割点
                    //BEGIN 求点双连通分量
                    bcc_cnt++;
                    bcc[bcc_cnt].clear();
                    Edge x;
                    do{
                        x=stk.top();
                        stk.pop();
                        if (bccno[x.u]!=bcc_cnt){
                            bcc[bcc_cnt].push_back(x.u);
                            bccno[x.u]=bcc_cnt;
                        }
                        if (bccno[x.v]!=bcc_cnt){
                            bcc[bcc_cnt].push_back(x.v);
                            bccno[x.v]=bcc_cnt;
                        }
                    }while (x.u!=u||x.v!=v);
                    //END
                }
                if (dfn[u]<lowv){//cut 桥
                    edges[i].cut=true;
                    edges[i^1].cut=true;
                }
            }
            else if (dfn[v]<dfn[u]){
                stk.push(e);//BEGIN-END 点双连通
                lowu=min(lowu,dfn[v]);
            }
        }
        if (fa<0&&child==1) iscut[u]=0;//割点
        low[u]=lowu;
        return lowu;
    }
    void find_bcc(){
        while (!stk.empty()) stk.pop();
        memset(dfn,0,sizeof(dfn));
        memset(iscut,0,sizeof(iscut));
        memset(bccno,0,sizeof(bccno));
        dfs_clock=bcc_cnt=0;
        for (int i=1;i<=n;i++){
            if (!dfn[i]) dfs(i,-1);
        }
    }
    //边双连通分量
    int block[maxn];
    int vis[maxn];
    int b_num;
    void b_dfs(int u){
        vis[u]=true;
        block[u]=b_num;
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            if (edges[i].cut) continue;
            int v=edges[i].to;
            if (!vis[v]) b_dfs(v);
        }
    }
    void find_block(){
        memset(block,0,sizeof(block));
        memset(vis,0,sizeof(vis));
        b_num=0;
        for (int i=1;i<=n;i++){
            if (!vis[i]){
                b_num++;
                b_dfs(i);
            }
        }
    }
};
/*==============================================*\
 | TwoSAT
 | INIT: init(n);addedge(u,v);节点编号0~n-1
 | CALL: add_clause(x,xval,y,yval) x=xval or y=yval
 |       add_con(x,xval) x=xval
 |       solve():bool;mark[i]:选取i
\*==============================================*/
struct TwoSAT{
    int head[maxn*2];
    EdgeNode edges[maxm*2];
    int edge,n;
    bool mark[maxn*2];
    int S[maxn*2],c;
    void init(int n){
        this->n=n;
        memset(mark,0,sizeof(mark));
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v){
        edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    // x = xval or y = yval
    void add_clause(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x^1,y);
        addedge(y^1,x);
    }
    // x = xval
    void add_con(int x,int xval){
        x=x*2+xval;
        addedge(x^1,x);
    }
    bool dfs(int x){
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for (int i=head[x];i!=-1;i=edges[i].next)
            if (!dfs(edges[i].to)) return false;
        return true;
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
};
/*==============================================*\
 | TwoSAT-Tarjan强连通
 | INIT: init(n),addedge(u,v),节点0~n-1
 | CALL: add_self(x,xval,y,yval) x!=xval->y=yval
 |       solve():bool
\*==============================================*/
struct TWOSAT{
    int head[maxn*2];
    EdgeNode edges[maxm*2];
    int edge,n;
    void init(int n){
        this->n=2*n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v){
        edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    // x = xval or y = yval
    void add_clause(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x^1,y);
        addedge(y^1,x);
    }
    //x=xval
    void add_con(int x,int xval){
        x=x*2+xval;
        addedge(x^1,x);
    }
    //x!=xval->y=yval
    void add_self(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x,y);
    }
    int pre[maxn],lowlink[maxn],sccno[maxn],scc_cnt,dfs_clock;
    stack<int>stk;
    void dfs(int u){
        pre[u]=lowlink[u]=++dfs_clock;
        stk.push(u);
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            }
            else if (!sccno[v]){
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if (lowlink[u]==pre[u]){
            scc_cnt++;
            int x;
            do{
                x=stk.top();
                stk.pop();
                sccno[x]=scc_cnt;
            }while (x!=u);
        }
    }
    void find_scc(int n){
        dfs_clock=scc_cnt=0;
        memset(sccno,0,sizeof(sccno));
        memset(pre,0,sizeof(pre));
        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++) if (!pre[i]) dfs(i);
    }
    bool solve(){
        find_scc(n);
        for (int i=0;i<n;i+=2){
            if (sccno[i]==sccno[i^1]) return false;
        }
        return true;
    }
};
/*==============================================*\
 | Dinic最大流
 | INIT: prepare(n,S,T);addedge(u,v,c);节点0~n
 | CALL: Dinic_flow():int
\*==============================================*/
struct edgenode{
    int to,flow,next;
};
struct Dinic{
    int node,src,dest,edge;
    int head[maxn],work[maxn],dis[maxn],q[maxn];
    edgenode edges[maxm];
    void prepare(int _node,int _src,int _dest){
        node=_node,src=_src,dest=_dest;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v,int c){
        edges[edge].flow=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
        edges[edge].flow=0,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
    }
    bool Dinic_bfs(){
        int i,u,v,l,r=0;
        for (i=0; i<node; i++) dis[i]=-1;
        dis[q[r++]=src]=0;
        for (l=0; l<r; l++){
            for (i=head[u=q[l]]; i!=-1; i=edges[i].next){
                if (edges[i].flow&&dis[v=edges[i].to]<0){
                    dis[q[r++]=v]=dis[u]+1;
                    if (v==dest) return true;
                }
            }
        }
        return false;
    }
    int Dinic_dfs(int u,int exp){
        if (u==dest) return exp;
        for (int &i=work[u],v,tmp; i!=-1; i=edges[i].next){
            if (edges[i].flow&&dis[v=edges[i].to]==dis[u]+1&&
                (tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0){
                edges[i].flow-=tmp;
                edges[i^1].flow+=tmp;
                return tmp;
            }
        }
        return 0;
    }
    int Dinic_flow(){
        int i,ret=0,delta;
        while (Dinic_bfs()){
            for (i=0;i<node;i++) work[i]=head[i];
            while (delta=Dinic_dfs(src,INF)) ret+=delta;
        }
        return ret;
    }
};
/*==============================================*\
 | 最小费用最大流
 | INIT: prepare(n,S,T);addedge(u,v,f,c);编号0~n-1
 | CALL: spfaflow():int
\*==============================================*/
struct edgenode_1{
    int to;//边的指向
    int flow;//边的容量
    int cost;//边的费用
    int next;//链表的下一条边
};
struct MinCost{
    edgenode_1 edges[maxm];
    int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
    int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];
    //head链表头，p记录可行流上节点对应的反向边，dis计算距离
    void prepare(int _node=0,int _src=0,int _dest=0){
        node=_node,src=_src,dest=_dest;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        edge=0;
    }
    void addedge(int u,int v,int f,int c){
        edges[edge].flow=f;edges[edge].cost=c;edges[edge].to=v;
        edges[edge].next=head[u];head[u]=edge++;
        edges[edge].flow=0;edges[edge].cost=-c;edges[edge].to=u;
        edges[edge].next=head[v];head[v]=edge++;
    }
    bool spfa(){
        int i,u,v,l,r=0,tmp;
        for (i=0;i<node;i++) dis[i]=INF;
        dis[q[r++]=src]=0;
        p[src]=p[dest]=-1;
        for (l=0;l!=r;((++l>=maxn)?l=0:l)){
            for (i=head[u=q[l]],vis[u]=false;i!=-1;i=edges[i].next){
                if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost)){
                    dis[v]=tmp;
                    p[v]=i^1;
                    if (vis[v]) continue;
                    vis[q[r++]=v]=true;
                    if (r>=maxn) r=0;
                }
            }
        }
        return p[dest]>=0;
    }
    int spfaflow(){
        int i,ret=0,delta;
        while (spfa()){//按记录原路返回求流量
            for (i=p[dest],delta=INF;i>=0;i=p[edges[i].to]){
                delta=min(delta,edges[i^1].flow);
            }
            for (int i=p[dest];i>=0;i=p[edges[i].to]){
                edges[i].flow+=delta;
                edges[i^1].flow-=delta;
            }
            ret+=delta*dis[dest];
        }
        return ret;
    }
};
int main(){
/*==============================================*\
 |
 | INIT:
 | CALL:
\*==============================================*/
    return 0;
}
