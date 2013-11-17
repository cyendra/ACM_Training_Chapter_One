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
int a[maxn];
typedef pair<int,int> PII;
deque<PII>q1,q2;
int main()
{
    int n,m,k;
    int ans,now;
    while (~scanf("%d%d%d",&n,&m,&k))
    {
        ans=0;
        now=0;
        q1.clear();
        q2.clear();
        REP(i,n)
        {
            scanf("%d",&a[i]);
            while (!q1.empty()&&q1.back().first<=a[i]) q1.pop_back();
            q1.push_back(mp(a[i],i));
            while (!q2.empty()&&q2.back().first>=a[i]) q2.pop_back();
            q2.push_back(mp(a[i],i));
            while (!q1.empty()&&!q2.empty()&&q1.front().first-q2.front().first>k)
            {
                if (q1.front().second<q2.front().second)
                {
                    now=q1.front().second+1;
                    q1.pop_front();
                }
                else
                {
                    now=q2.front().second+1;
                    q2.pop_front();
                }
            }
            if (!q1.empty()&&!q2.empty()&&q1.front().first-q2.front().first>=m)
                ans=max(ans,i-now+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
