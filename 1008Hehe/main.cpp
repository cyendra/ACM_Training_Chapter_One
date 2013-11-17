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

const int INF = 0x3f3f3f3f;
const long long INFF = 1LL << 60;
const double EPS = 1e-9;
const double OO = 1e15;
const double PI = acos(-1.0); //M_PI;
typedef long long LL;

const LL MOD=10007;

char str[20000];
int bit[22222];
int m;
LL f[22222];
LL ans;
int main()
{
    int T;
    clr(f,0);
    f[0]=1;
    f[1]=1;
    for (int i=2;i<=10086;i++)
    {
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
    scanf("%d",&T);
    REP_1(loop,T)
    {
        clr(bit,0);
        scanf("%s",str);
        int len=strlen(str);
        m=0;
        bool sps=false;
        REP(i,len)
        {
            if (str[i]=='h'&&str[i+1]=='e')
            {
                bit[m++]=1;
                sps=false;
                i++;
            }
            else if (!sps)
            {
                bit[m++]=0;
                sps=true;
            }
        }
        ans=1;
        int cnt=0;
        bool cru=true;
        REP(i,m)
        {
            if (bit[i]==1)
            {
                cru=false;
                cnt++;
            }
            if (bit[i]==0&&!cru)
            {
                cru=true;
                ans=ans*f[cnt]%MOD;
                cnt=0;
            }
            if (i==m-1&&!cru)
            {
                cru=true;
                ans=ans*f[cnt]%MOD;
                cnt=0;
            }
        }
        cout<<"Case "<<loop<<": "<<ans<<endl;
    }
    return 0;
}
