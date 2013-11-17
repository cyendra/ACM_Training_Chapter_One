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
const int maxn=555;
int n,m;

struct StoerWagner{
    int mat[maxn][maxn];
    int dis[maxn];
    int S,T;
    int n;
    bool vis[maxn],del[maxn];
    void init(int n){
        memset(mat,0,sizeof(mat));
        this->n=n;
    }
    void addedge(int u,int v,int c){
        mat[u][v]+=c;
        mat[v][u]+=c;
    }
    int search(int ct){
        int tmp,mx,cut;
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
        T=S=-1;
        for (int i=0;i<n-ct;i++){
            mx=-1;
            for (int j=0;j<n;j++){
                if (!vis[j]&&!del[j]&&dis[j]>mx){
                    mx=dis[j];
                    tmp=j;
                }
            }
            S=T;
            T=tmp;
            cut=mx;
            vis[T]=true;
            for (int j=0;j<n;j++){
                if (!vis[j]&&!del[j]){
                    dis[j]+=mat[T][j];
                }
            }
        }
        return cut;
    }
    int minimumCut(){
        int ans=INF;
        memset(del,0,sizeof(del));
        for (int i=0;i<n-1;i++){
            int cut=search(i);
            if (cut<ans) ans=cut;
            if (ans==0) return 0;
            del[T]=true;
            for (int j=0;j<n;j++){
                if (!del[j]){
                    mat[S][j]+=mat[T][j];
                    mat[j][S]+=mat[T][j];
                }
            }
        }
        return ans;
    }
}solver;

int main()
{
    while (~scanf("%d%d",&n,&m)){
        solver.init(n);
        while (m--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            solver.addedge(x,y,z);
        }
        printf("%d\n",solver.minimumCut());
    }
    return 0;
}
