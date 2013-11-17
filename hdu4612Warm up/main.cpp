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
    int node;
    void init(int n)
    {
        clr(head,-1);
        node=n;
        edge=0;
    }
    void addedge(int u,int v,int c)
    {
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
} graph;



int tarjan(int u,int fa)
{
    int v,lowv,lowu;
    lowu=dfn[u]=++dfs_clock;
    stak[top++]=u;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        v=e[i].v;
        if(v==fa)continue;
        if(!dfn[v])
        {
            lowv=tarjan(v,u);
            if(lowv>dfn[u])
            {
                e[i].vis=e[i^1].vis=1;///标记为桥
                ++brige;
            }
            lowu=min(lowv,lowu);
        }
        else if(!e_to[v]&&dfn[v]<lowu)
            lowu=dfn[v];
    }
    if(lowu==dfn[u])
    {
        ++bcc_no;
        do
        {
            v=stak[--top];
            e_to[v]=bcc_no;///边所属的双连通分量

        }
        while(v!=u);
    }
    return lowu;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
