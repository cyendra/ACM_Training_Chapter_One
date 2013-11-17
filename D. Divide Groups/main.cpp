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
const int maxn=811;
const int maxm=151111;
/*==============================================*\
 | TwoSAT-Tarjan强连通
 | INIT: init(n),addedge(u,v),节点0~n-1
 | CALL: add_self(x,xval,y,yval) x!=xval->y=yval
 |       solve():bool
\*==============================================*/
struct EdgeNode{
    int to;
    int w;
    int next;
};
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
}solver;
int n;
int a[maxn][maxn];
int main()
{
    while (~scanf("%d",&n)){
        memset(a,0,sizeof(a));
        solver.init(n);
        for (int i=1;i<=n;i++){
            int t;
            while (scanf("%d",&t)){
                if (t==0) break;
                a[i][t]=1;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (a[i][j]+a[j][i]<2&&i!=j){
                    //cerr<<i<<" "<<j<<endl;
                    solver.add_clause(i-1,1,j-1,1);
                    solver.add_clause(i-1,0,j-1,0);
                }
            }
        }
        if (solver.solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}
