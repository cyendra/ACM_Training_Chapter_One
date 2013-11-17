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

const int maxn=111111;
const int maxm=511111;
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
    void addedge(int u,int v,int c=1)
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
};
SGRAPH solver;
bool mp[111][111];
int main()
{
    int ans1,ans2;
    int idd,odd;
    while (~scanf("%d",&n))
    {
        clr(mp,0);
        solver.init();
        REP_1(i,n)
        {
            int xt;
            while (~scanf("%d",&xt))
            {
                if (xt==0) break;
                solver.addedge(i,xt);
            }
        }
        solver.find_scc(n);
        REP(u,n)
        {
            for (int i=solver.head[u];i!=-1;i=solver.edges[i].next)
            {
                int v=solver.edges[i].to;
                if (solver.sccno[u]!=solver.sccno[v])
                {
                    mp[solver.sccno[u]][solver.sccno[v]]=true;
                }
            }
        }
        //Display_1(mp,solver.scc_cnt,solver.scc_cnt);
        ans1=ans2=0;
        m=solver.scc_cnt;
        REP_1(i,m)
        {
            idd=0;
            odd=0;
            REP_1(j,m)
            {
                if (mp[j][i]) idd++;
                if (mp[i][j]) odd++;
            }
            if (!idd) ans1++;
            if (!odd) ans2++;
        }
        ans2=max(ans1,ans2);
        if (m==1) ans2=0;
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}
