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
const int maxm=2200000;
int n,m;

struct EDGENODE{
    int to;
    int w;
    bool cut;
    int next;
};
struct SEDGE{
    int u;
    int v;
    SEDGE(int uu=0,int vv=0){u=uu;v=vv;}
};
struct BCC_GRAPH{
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
        edges[edge].cut=0,edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    //BCC_Tarjan
    int dfn[maxn],low[maxn],bccno[maxn],dfs_clock,bcc_cnt;
    bool iscut[maxn];
    vector<int>bcc[maxn];
    stack<SEDGE>stk;
    int dfs(int u,int fa)
    {
        int lowu=dfn[u]=++dfs_clock;
        int child=0;
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            int v=edges[i].to;
            if (v==fa) continue;
            SEDGE e=SEDGE(u,v);
            if (!dfn[v])
            {
                stk.push(e);
                child++;
                int lowv=dfs(v,u);
                lowu=min(lowu,lowv);
                if (dfn[u]<=lowv) //cut 割点
                {
                    iscut[u]=true;
                    //done 点双连通
                    bcc_cnt++;
                    bcc[bcc_cnt].clear();
                    SEDGE x;
                    do{
                        x=stk.top();
                        stk.pop();
                        if (bccno[x.u]!=bcc_cnt)
                        {
                            bcc[bcc_cnt].push_back(x.u);
                            bccno[x.u]=bcc_cnt;
                        }
                        if (bccno[x.v]!=bcc_cnt)
                        {
                            bcc[bcc_cnt].push_back(x.v);
                            bccno[x.v]=bcc_cnt;
                        }
                    }while (x.u!=u||x.v!=v);
                    //over
                }
                if (dfn[u]<lowv)  //cut 桥
                {
                    edges[i].cut=true;
                    edges[i^1].cut=true;
                }
            }
            else if (dfn[v]<dfn[u])
            {
                stk.push(e);//done
                lowu=min(lowu,dfn[v]);
            }
        }
        if (fa<0&&child==1) iscut[u]=0;
        low[u]=lowu;
        return lowu;
    }
    void find_bcc(int n)
    {
        while (!stk.empty()) stk.pop();
        clr(dfn,0);
        clr(iscut,0);
        clr(bccno,0);
        dfs_clock=bcc_cnt=0;
        REP_1(i,n)
        {
            if (!dfn[i]) dfs(i,-1);
        }
    }
}solver;

int A[maxn][maxn];

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        if (n==0&&m==0) break;
        solver.init();
        REP(i,m)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            A[x][y]=true;
            A[y][x]=true;
        }
        REP_1(i,n)
    }
    return 0;
}
