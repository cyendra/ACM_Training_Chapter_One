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
bool vis[maxn];
int cnt;
/*==============================================*\
 | Dinic最大流
 | INIT: prepare(n,S,T);addedge(u,v,c);节点0~n
 | CALL: Dinic_flow():int
\*==============================================*/
struct edgenode{
    int to;
    LL flow;
    int next;
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
    void addedge(int u,int v,LL c){
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
    LL Dinic_dfs(int u,LL exp){
        if (u==dest) return exp;
        int v;
        LL tmp;
        for (int &i=work[u]; i!=-1; i=edges[i].next){
            if (edges[i].flow&&dis[v=edges[i].to]==dis[u]+1&&
                (tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0){
                edges[i].flow-=tmp;
                edges[i^1].flow+=tmp;
                return tmp;
            }
        }
        return 0;
    }
    LL Dinic_flow(){
        int i;
        LL ret=0,delta;
        while (Dinic_bfs()){
            for (i=0;i<node;i++) work[i]=head[i];
            while (delta=Dinic_dfs(src,INFF)) ret+=delta;
        }
        return ret;
    }
    void dfs(int u){
        vis[u]=true;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (vis[v]) continue;
            if (edges[i].flow>0){
                dfs(v);
                cnt++;
            }
        }
    }
}solver;

int n,m;
LL b[maxn];

LL sum;
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        clr(vis,0);
        sum=0;
        solver.prepare(n+2,0,n+1);
        REP_1(i,n){
            scanf("%I64d",&b[i]);
            if (b[i]>0) sum+=b[i];
            if (b[i]>0) solver.addedge(0,i,b[i]);
            if (b[i]<0) solver.addedge(i,n+1,-b[i]);
        }
        REP(i,m){
            int x,y;
            scanf("%d%d",&x,&y);
            solver.addedge(x,y,INFF);
        }
        LL ans=sum-solver.Dinic_flow();
        cnt=0;
        solver.dfs(0);
        printf("%d ",cnt);
        printf("%I64d\n",ans);
    }
    return 0;
}

