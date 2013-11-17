
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
const int maxn=110000;

/**array**/
bool vis[maxn];
int a[maxn];
int d[maxn];
int pal[maxn];
int ans[maxn];

/**val**/
int n,m;

/**struct**/
struct Query{
    int L;
    int R;
    int idx;
}qu[maxn];
bool cmp(Query a,Query b){return a.L<b.L;}

/**BIT**/
int tree[maxn];
int lowbit(int x){return x&(-x);}
void add(int x,int d){
    for (int i=x;i<=n;i+=lowbit(i)) tree[i]+=d;
}
int sum(int x){
    int ret=0;
    for (int i=x;i>0;i-=lowbit(i)) ret+=tree[i];
    return ret;
}

/**function**/
void init()
{
    clr(vis,0);
    clr(d,0);
    clr(tree,0);
}

void input()
{
    scanf("%d%d",&n,&m);
    REP_1(i,n){
        scanf("%d",&a[i]);
        pal[a[i]]=i;
    }
    REP_1(i,m)
    {
        scanf("%d%d",&qu[i].L,&qu[i].R);
        qu[i].idx=i;
    }
}

void solve()
{
    sort(qu+1,qu+m+1,cmp);
    REP_1(i,n)
    {
        if (vis[a[i]+1]) d[i]++;
        if (vis[a[i]-1]) d[i]++;
        if (d[i]==0) add(i,1);
        if (d[i]==2) add(i,-1);
        vis[a[i]]=true;
    }
    int l=1;
    REP_1(i,m)
    {
        while (l<qu[i].L)
        {
            if (a[l]+1<=n&&pal[a[l]+1]>l) add(pal[a[l]+1],1);
            if (a[l]-1>=1&&pal[a[l]-1]>l) add(pal[a[l]-1],1);
            l++;
        }
        ans[qu[i].idx]=sum(qu[i].R)-sum(qu[i].L-1);
    }
}

void output()
{
    REP_1(i,m) printf("%d\n",ans[i]);
}

/**main**/
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        input();
        solve();
        output();
    }
    return 0;
}
