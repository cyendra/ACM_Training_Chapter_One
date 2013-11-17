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
/**
    f[i]=min( f[j]+(sum[i]-sum[j])^2+M )
    y为f[j]+sum[j]^2，x为2*sum[j]，斜率为sum[i]，截距为f[i]
**/
const int maxn=550000;
int n,m;
int a[maxn];
int f[maxn];
int que[maxn];
int head,tail;
int sum[maxn];
int gety(int j){return f[j]+sum[j]*sum[j];}
int getx(int j){return 2*sum[j];}
int dp_sol(int i,int j){return f[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;}
bool cmp_idx(int i,int j,int k)
{
    return (gety(i)-gety(j))*(getx(j)-getx(k))<=(gety(j)-gety(k))*(getx(i)-getx(j));
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        memset(f,0,sizeof(f));
        sum[0]=0;
        REP_1(i,n)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        head=tail=0;
        que[tail++]=0;
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            while (tail-head>1&&dp_sol(i,que[head])>=dp_sol(i,que[head+1])) head++;
            f[i]=dp_sol(i,que[head]);
            while (tail-head>1&&cmp_idx(i,que[tail-1],que[tail-2])) tail--;
            que[tail++]=i;
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
