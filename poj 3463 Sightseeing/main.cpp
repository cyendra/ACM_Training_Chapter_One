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
const int maxm=31111;

struct EdgeNode{
    int to;
    int w;
    int next;
};

struct HeapNode{
    int d,u;
    bool bs;
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};

struct Dijkstra{
    EdgeNode edges[maxm];
    int head[maxn];
    int edge,n;
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedges(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn][2];
    int dis[maxn][2];
    int num[maxn][2];
    int dijkstra(int s,int t){
        priority_queue<HeapNode>que;
        memset(done,0,sizeof(done));
        memset(num,0,sizeof(num));
        for (int i=0;i<=n;i++){
            dis[i][0]=INF;
            dis[i][1]=INF;
        }
        dis[s][0]=0;
        num[s][0]=1;
        que.push((HeapNode){0,s,0});
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            bool bs=x.bs;
            if (done[u][bs]) continue;
            done[u][bs]=true;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                int nw=edges[i].w+dis[u][bs];
                if (dis[v][0]>nw){
                    if (dis[v][0]!=INF){
                        dis[v][1]=dis[v][0];
                        num[v][1]=num[v][0];
                        que.push((HeapNode){dis[v][1],v,1});
                    }
                    dis[v][0]=nw;
                    num[v][0]=num[u][bs];
                    que.push((HeapNode){dis[v][0],v,0});
                }
                else if (dis[v][0]==nw){
                    num[v][0]+=num[u][bs];
                }
                else if (dis[v][1]>nw){
                    dis[v][1]=nw;
                    num[v][1]=num[u][bs];
                    que.push((HeapNode){dis[v][1],v,1});
                }
                else if (dis[v][1]==nw){
                    num[v][1]+=num[u][bs];
                }
            }
        }
        if (dis[t][0]+1==dis[t][1])
        {
            return num[t][0]+num[t][1];
        }
        else
        {
            return num[t][0];
        }
    }
}solver;

int n,m;

int main()
{
    int T,s,f;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        solver.init(n);
        while (m--)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            solver.addedges(x,y,w);
        }
        scanf("%d%d",&s,&f);
        int ans=solver.dijkstra(s,f);
        printf("%d\n",ans);
    }
    return 0;
}

