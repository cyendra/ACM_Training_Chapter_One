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

const int direct4[4][2]= { {0,1},{1,0},{0,-1},{-1,0} };
const int direct8[8][2]= { {0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1} };
const int direct3[6][3]= { {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };

const int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0); //M_PI;


const int maxn=111111;
const int maxm=511111;
int n,m;

struct EDGENODE
{
    int to;
    int w;
    int next;
};
struct SGRAPH
{
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
    int num[maxn];
    void dfs(int u)
    {
        pre[u]=lowlink[u]=++dfs_clock;
        stk.push(u);
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            int v=edges[i].to;
            if (!pre[v])
            {
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            }
            else if (!sccno[v])
            {
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if (lowlink[u]==pre[u])
        {
            scc_cnt++;
            int x;
            do
            {
                x=stk.top();
                stk.pop();
                sccno[x]=scc_cnt;
                num[scc_cnt]++;
            }
            while (x!=u);
        }
    }
    void find_scc(int n)
    {
        clr(num,0);
        dfs_clock=scc_cnt=0;
        clr(sccno,0);
        clr(pre,0);
        while (!stk.empty()) stk.pop();
        REP_1(i,n) if (!pre[i]) dfs(i);
    }
} solver;

int idd[maxn];
int odd[maxn];
LL sumd;

int main()
{
    int cas=0;
    int T;
    LL ans;
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
        printf("Case %d: ",++cas);
        if (solver.scc_cnt==1)
        {
            printf("-1\n");
        }
        else
        {
            int neu,nev;
            int scc=solver.scc_cnt;
            //cerr<<scc<<endl;
            clr(idd,0);
            clr(odd,0);
            REP_1(u,n)
            {
                neu=solver.sccno[u];
                for (int i=solver.head[u]; i!=-1; i=solver.edges[i].next)
                {
                    int v=solver.edges[i].to;
                    nev=solver.sccno[v];
                    //done
                    if (neu!=nev)
                    {
                    idd[nev]++;
                    odd[neu]++;
                    }

                }
            }
            sumd=0;
            for (int i=1;i<=scc;i++)
            {
                sumd+=solver.num[i];
                //cerr<<sumd<<endl;
            }
            LL XM=INFF;
            LL tmp=0;
            for (int i=1;i<=scc;i++)
            {
                if (idd[i]==0||odd[i]==0)
                {
                    tmp=solver.num[i]*(sumd-solver.num[i]);
                    //cerr<<endl<<solver.num[i]<<"id="<<i<<" tmp="<<tmp<<endl;
                    XM=min(XM,tmp);
                }
            }
            ans=LL(n)*LL(n-1)-m-XM;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
