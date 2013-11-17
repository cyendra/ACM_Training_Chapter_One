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

int n,m,s;
struct node{
    int local;
    int cost;
}a[55][1111];
int f[55][1111];
/** f[i][j]=min(f[i-1][k]+abs(a[i][j].local-a[i-1][k].local)+a[i][j].cost) **/
int head,tail;
int que[1111];
int dp(int i,int j,int k)
{
    return f[i-1][k]+abs(a[i][j].local-a[i-1][k].local)+a[i][j].cost;
}

bool cmp(node a,node b)
{
    return a.local<b.local;
}

int main()
{
    int T;
    cin>>T;
    while (cin>>n>>m>>s)
    {
        clr(f,INF);
        REP_1(i,n) REP_1(j,m)
            cin>>a[i][j].local;
        REP_1(i,n)
        {
            REP_1(j,m) cin>>a[i][j].cost;
            sort(a[i]+1,a[i]+m+1,cmp);
        }
        REP_1(i,m)
        {
            f[1][i]=abs(s-a[1][i].local)+a[1][i].cost;
        }
        FOR_1(i,2,n)
        {
            head=tail=0;
            int k=1;
            FOR_1(j,1,m)
            {
                while (k<=m&&a[i-1][k].local<=a[i][j].local)
                {
                    int t=dp(i,j,k);
                    while (head<tail&&dp(i,j,que[tail-1])>=t) tail--;
                    que[tail++]=k;
                    k++;
                }
                if (head<tail) f[i][j]=dp(i,j,que[head]);
            }
            head=tail=0;
            k=m;
            DWN_1(j,m,1)
            {
                while (k>=1&&a[i-1][k].local>a[i][j].local)
                {
                    int t=dp(i,j,k);
                    while (head<tail&&dp(i,j,que[tail-1])>=t) tail--;
                    que[tail++]=k;
                    k--;
                }
                if (head<tail) f[i][j]=min(f[i][j],dp(i,j,que[head]));
            }
        }
        int ans=INF;
        REP_1(i,m)
        {
            ans=min(ans,f[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
