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
const int maxm=11111;
int n,m;

struct EDGENODE{
    int to;
    int w;
    int next;
};
struct SGRAPH{
    int head[maxn];
    EDGENODE edges[maxm];
    int edge;
    void init()
    {
        clr(head,-1);
        edge=0;
    }
    void addedge(int u,int v,int c=0)
    {
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    int pre[maxn],lowlink[maxn],sccno[maxn],scc_cnt,dfs_clock;
    stack<int>stk;
    void dfs(int u)
    {
        pre[u]=lowlink[u]=++dfs_clock;
        stk.push(u);
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            } else if (!sccno[v]){
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
    void find_scc(int n)
    {
        dfs_clock=scc_cnt=0;
        clr(sccno,0);
        clr(pre,0);
        while (!stk.empty()) stk.pop();
        REP_1(i,n) if (!pre[i]) dfs(i);
    }
}solver;

bool a[maxn][maxn];

bool topsort()
{
    int idd[maxn];
    int cnt=0;
    queue<int>que;
    clr(idd,0);
    REP_1(i,m)
    {
        REP_1(j,m)
        {
            if (a[j][i]) idd[i]++;
        }
        if (idd[i]==0) que.push(i);
    }
    if (que.size()>1) return false;
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        cnt=0;
        REP_1(v,m)
        {
            if (a[u][v])
            {
                idd[v]--;
                if (idd[v]==0) {que.push(v);cnt++;};
            }
        }
        if (cnt>1) return false;
    }
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        solver.init();
        REP(i,m)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            solver.addedge(x,y);
        }
        solver.find_scc(n);
        m=solver.scc_cnt;
        clr(a,0);
        REP_1(u,n)
        {
            for (int i=solver.head[u];i!=-1;i=solver.edges[i].next)
            {
                int v=solver.edges[i].to;
                if (solver.sccno[u]==solver.sccno[v]) continue;
                a[solver.sccno[u]][solver.sccno[v]]=true;
            }
        }
        if (topsort()) puts("Yes");
        else puts("No");
    }
    return 0;
}
