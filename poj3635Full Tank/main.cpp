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

const int maxn=2111;
const int maxm=31111;
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
    void init(){
        clr(head,-1);
        edge=0;
    }
    void addedge(int u,int v,int c=0){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
}dragonborn;
struct data{
    int u,f,c;
    data(){}
    data(int u,int f,int c){
        this->u=u;
        this->f=f;
        this->c=c;
    }
    friend bool operator<(const data& a,const data& b)
    {
        return a.c>b.c;
    }
};

int cost[maxn];
bool vis[maxn][111];
int solve(SGRAPH& G,int V,int s,int e)
{
    priority_queue<data>que;
    clr(vis,0);
    que.push(data(s,0,0));
    while (!que.empty())
    {
        data top=que.top();
        que.pop();
        vis[top.u][top.f]=true;
        if (top.u==e) return top.c;
        if (top.f<V&&!vis[top.u][top.f+1])
            que.push(data(top.u,top.f+1,top.c+cost[top.u]));
        for (int i=G.head[top.u];i!=-1;i=G.edges[i].next)
        {
            if (top.f>=G.edges[i].w&&!vis[G.edges[i].to][top.f-G.edges[i].w])
                que.push(data(G.edges[i].to,top.f-G.edges[i].w,top.c));
        }
    }
    return -1;
}

int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        int Q;
        dragonborn.init();
        REP(i,n) scanf("%d",&cost[i]);
        REP(i,m)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            dragonborn.addedge(u,v,d);
            dragonborn.addedge(v,u,d);
        }
        scanf("%d",&Q);
        while (Q--)
        {
            int c,s,e;
            scanf("%d%d%d",&c,&s,&e);
            int ret=solve(dragonborn,c,s,e);
            if (ret!=-1) printf("%d\n",ret);
            else printf("impossible\n");
        }
    }
    return 0;
}
