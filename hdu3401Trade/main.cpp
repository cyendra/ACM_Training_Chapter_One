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

const int maxn=2222;
int f[maxn][maxn];
int AP[maxn],BP[maxn],AS[maxn],BS[maxn];
int MaxP,W,T;
/**
    f[i][j]=max(f[i-1][j],f[i-W-1][k]-AP[i]*(j-k),f[i-W-1][k]+BP[i]*(k-j))
    f[i-W-1][k]-AP[i]*(j-k)
    =f[i-W-1][k]+AP[i]*k-AP[i]*j
    f[i-W-1][k]+BP[i]*(k-j)
    =f[i-W-1][k]+BP[i]*k-BP[i]*j
**/
int que[maxn];
int idx[maxn];

int main()
{
    int CAS;
    int head,tail,ans;
    scanf("%d",&CAS);
    while (CAS--)
    {
        scanf("%d%d%d",&T,&MaxP,&W);
        REP_1(i,T)
        {
            scanf("%d%d%d%d",&AP[i],&BP[i],&AS[i],&BS[i]);
        }
        REP_1(i,MaxP) f[0][i]=-INF;
        f[0][0]=0;
        ans=0;
        FOR_1(i,2,T)
        {
            FOR_1(j,0,MaxP) f[i][j]=f[i-1][j];
            if (i-W-1<1)
            {
                FOR_1(j,0,AS[i]) f[i][j]=max(f[i][j],-AP[i]*j);
                continue;
            }
            head=tail=0;
            FOR_1(j,0,MaxP)
            {
                while (head<tail&&que[tail-1]<=f[i-W-1][j]+AP[i]*j) tail--;
                que[tail]=f[i-W-1][j]+AP[i]*j;
                idx[tail++]=j;
                while (head<tail&&j-idx[head]>AS[i]) head++;
                f[i][j]=max(f[i][j],que[head]-AP[i]*j);
                ans=max(ans,f[i][j]);
            }
            head=tail=0;
            DWN_1(j,MaxP,0)
            {
                while (head<tail&&que[tail-1]<=f[i-W-1][j]+BP[i]*j) tail--;
                que[tail]=f[i-W-1][j]+BP[i]*j;
                idx[tail++]=j;
                while (head<tail&&idx[head]-j>BS[i]) head++;
                f[i][j]=max(f[i][j],que[head]-BP[i]*j);
                ans=max(ans,f[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
