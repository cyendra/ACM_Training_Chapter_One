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

const int eps=1e-6;
int cmp(double a,double b){
    if (abs(a-b)<eps) return 0;
    if (a>b) return 1;
    else return -1;
}

const int maxn=211111;
const int maxm=1111111;
int n,m;
struct EdgeNode{
    int to;
    double pl;
    int next;
};
EdgeNode edges[maxm];
int head[maxn],edge;
bool vis[maxn];
int dist[maxn];
double px[maxn];
int pre[maxn];
int s,t;
void addedge(int u,int v,double p){
    edges[edge].pl=p,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}
void init(){
    memset(head,-1,sizeof(head));
    edge=0;
}

void bfs(){
    queue<int>que;
    while (!que.empty()) que.pop();
    REP_1(i,n) dist[i]=INF,vis[i]=0;
    que.push(s);
    dist[s]=1;
    vis[s]=true;
    while (!que.empty()){
        int u=que.front();
        que.pop();
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!vis[v]){
                if (dist[v]>dist[u]+1) dist[v]=dist[u]+1;
                que.push(v);
                vis[v]=true;
            }
        }
    }
}
void pix(){
    queue<int>que;
    while (!que.empty()) que.pop();
    REP_1(i,n) px[i]=0;
    que.push(s);
    px[s]=1.0;
    while (!que.empty()){
        int u=que.front();
        que.pop();
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (dist[v]==dist[u]+1){
                if (cmp(px[u]*edges[i].pl,px[v])>0){
                    px[v]=px[u]*edges[i].pl;
                    pre[v]=u;
                    que.push(v);
                }
            }
        }
    }
}

void dfs(int u){
    vis[u]=true;
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        if (dist[v]+1!=dist[u]||vis[v]) continue;
        if (px[v]==0) dfs(v);
        if (px[v]*edges[i].pl>px[u]){
            px[u]=px[v]*edges[i].pl;
            pre[u]=v;
        }
    }

}
int main()
{
    while (~scanf("%d%d",&n,&m)){
        scanf("%d%d",&s,&t);
        init();
        REP_1(i,m){
            int x,y;
            double d;
            scanf("%d%d%lf",&x,&y,&d);
            addedge(x,y,1.0-d/100.0);
            addedge(y,x,1.0-d/100.0);
        }
        bfs();
        clr(vis,0);
        clr(px,0);
        px[s]=1.0;
        dfs(t);
        printf("%d %0.2f\n",dist[t],1.0-px[t]);
        stack<int>stk;
        while (t!=0){
            stk.push(t);
            t=pre[t];
        }
        while (!stk.empty()){
            printf("%d ",stk.top());
            stk.pop();
        }
        printf("\n");
    }
    return 0;
}
