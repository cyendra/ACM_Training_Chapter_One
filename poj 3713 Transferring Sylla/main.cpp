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
const int maxn=1111;
const int maxm=111111;
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
bool dead[maxn];
int cutnum;
struct EdgeNode_1{
    int to;
    int w;
    int next;
    bool cut;
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
    int dfn[maxn],low[maxn],dfs_clock;
    bool iscut[maxn];
    int dfs(int u,int fa){
        int lowu=dfn[u]=++dfs_clock;
        int child=0;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==fa) continue;
            if (dead[v]) continue;
            if (!dfn[v]){
                child++;
                int lowv=dfs(v,u);
                lowu=min(lowu,lowv);
                if (dfn[u]<=lowv){
                    if (!iscut[u]) cutnum++;
                    iscut[u]=true;//割点
                    //cerr<<"u is cut "<<u<<" num="<<cutnum<<endl;
                }
            }
            else if (dfn[v]<dfn[u]){
                lowu=min(lowu,dfn[v]);
            }
        }
        if (fa<0&&child==1){
            if (iscut[u]) cutnum--;
            //cerr<<"u is not cut "<<u<<" num="<<cutnum<<endl;
            iscut[u]=0;//割点
        }
        low[u]=lowu;
        return lowu;
    }
    void find_bcc(){
        memset(dfn,0,sizeof(dfn));
        memset(iscut,0,sizeof(iscut));
        dfs_clock=0;
        bool ok=false;
        for (int i=1;i<=n;i++){
            if (!dfn[i]&&!dead[i]){
                if (ok) {
                    cutnum++;
                    break;
                }
                dfs(i,-1);
                if (cutnum>0) break;
                ok=true;
            }
        }
    }
}solver;

int n,m;
int main()
{
    while (~scanf("%d%d",&n,&m)){
        if (n==0&&m==0) break;
        solver.init(n);
        REP(i,m){
            int x,y;
            scanf("%d%d",&x,&y);
            x++;
            y++;
            solver.addedge(x,y);
            solver.addedge(y,x);
        }
        memset(dead,0,sizeof(dead));
        bool ans=true;
        REP_1(i,n){
            dead[i]=true;
            cutnum=0;
            solver.find_bcc();
            //cerr<<i<<" cut="<<cutnum<<endl;
            if (cutnum>0){
                ans=false;
                break;
            }
            dead[i]=false;
        }
        if (ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
