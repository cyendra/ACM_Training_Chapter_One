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

const int maxn=50001;
class CRMQ
{
    private:
    int Max[20][maxn];
    int Min[20][maxn];
    int idx[maxn];
    public:
    int val[maxn];
    void initRMQ(int n)
    {
        idx[0]=-1;
        for (int i=1; i<=n; i++){
            idx[i]=(i&(i-1))?idx[i-1]:idx[i-1]+1;
            Min[0][i]=Max[0][i]=val[i];
        }
        for (int i=1; i<=idx[n]; i++){
            int limit=n+1-(1<<i);
            for (int j=1; j<=limit; j++){
                Min[i][j]=min(Min[i-1][j],Min[i-1][j+(1<<i>>1)]);
                Max[i][j]=max(Max[i-1][j],Max[i-1][j+(1<<i>>1)]);
            }
        }
    }
    int getval(int a,int b)
    {
        int t=idx[b-a+1];
        b-=(1<<t)-1;
        return max(Max[t][a],Max[t][b])-min(Min[t][a],Min[t][b]);
    }
};
CRMQ sol;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    REP_1(i,n) scanf("%d",&sol.val[i]);
    sol.initRMQ(n);
    while (m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",sol.getval(a,b));
    }
    return 0;
}
