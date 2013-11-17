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
const int maxn=411111;
const int maxm=11111111;

/*==============================================*\
 | Dijkstra+堆优化
 | INIT: init(n);addedge(u,v,c);节点编号0~n
 | CALL: dijkstra(int s);dis[]:最短路;pre[]:前驱
\*==============================================*/
struct EdgeNode{
    int to;
    int w;
    int next;
};
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
    void init(int nn){
        this->n=nn;
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
}solver;

int n,m,c;
int flr[maxn];
bool vis[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&n,&m,&c);
        solver.init(n+n+n);
        for (int i=1;i<=n;i++){
            scanf("%d",&flr[i]);
            solver.addedge(i,flr[i]+n+n,0);
            solver.addedge(flr[i]+n,i,0);
        }
        for (int i=1;i<n;i++){
            solver.addedge(i+n+n,i+1+n,c);
            solver.addedge(i+1+n+n,i+n,c);
        }
        for (int i=1;i<=m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            solver.addedge(x,y,z);
            solver.addedge(y,x,z);
        }
        solver.dijkstra(1);
        if (solver.dis[n]==INF) printf("Case #%d: %d\n",cas,-1);
        else printf("Case #%d: %d\n",cas,solver.dis[n]);
    }
    return 0;
}
