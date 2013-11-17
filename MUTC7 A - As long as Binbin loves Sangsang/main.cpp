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
const int maxm=63520;
int n,m;

struct EDGENODE{
    int to;
    LL w;
    int k;
    int next;
};
struct spnode{
    int u;
    LL len;
    LL stp;
    int k;
    spnode(int a=0,LL b=0,LL c=0,int d=0):u(a),len(b),stp(c),k(d){}
};

class CSPFA{
private:
    EDGENODE edges[maxm];
    int head[maxn],edge,node;
    queue<spnode>que;
public:
    LL dist[maxn][4];
    LL step[maxn][4];
    void addedge(int u,int v,LL c,int tp){
        edges[edge].w=c,edges[edge].k=tp,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
        edges[edge].w=c,edges[edge].k=tp,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
    }
    void init(int n){
        memset(head,-1,sizeof(head));
        edge=0;
        node=n;
    }
    void SPFA(int src)
    {
        for (int i=0;i<=node;i++) REP(j,4) dist[i][j]=INFF;
        while (!que.empty()) que.pop();
        que.push(spnode(src,0,0,3));
        while (!que.empty()){
            spnode topnode=que.front();
            que.pop();
            int k=(topnode.k+1)%4;
            LL len=topnode.len;
            LL stp=topnode.stp;
            int top=topnode.u;
            for (int i=head[top];i!=-1;i=edges[i].next)
            {
                int v=edges[i].to;
                if (k!=edges[i].k) continue;
                if ( dist[v][k]>len+edges[i].w||
                    (dist[v][k]==len+edges[i].w&&step[v][k]<stp+1) )
                {
                    dist[v][k]=len+edges[i].w;
                    step[v][k]=stp+1;
                    que.push(spnode(v,dist[v][k],step[v][k],k));
                }
            }
        }
    }
}solver;

int apm(char c)
{
    if (c=='L') return 0;
    if (c=='O') return 1;
    if (c=='V') return 2;
    if (c=='E') return 3;
    return -1;
}

int main()
{
    int T,cas=0;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        solver.init(n);
        while (m--)
        {
            int u,v,w;
            char c;
            cin>>u>>v>>w>>c;
            solver.addedge(u,v,w,apm(c));
        }
        solver.SPFA(1);
        if (solver.dist[n][3]==INFF)
            cout<<"Case "<<++cas<<": Binbin you disappoint Sangsang again, damn it!"<<endl;
        else
            cout<<"Case "<<++cas<<": Cute Sangsang, Binbin will come with a donkey after travelling "<<solver.dist[n][3]<<" meters and finding "<<solver.step[n][3]/4<<" LOVE strings at last."<<endl;
    }
    return 0;
}
