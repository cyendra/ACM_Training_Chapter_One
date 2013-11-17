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
    f[i][j]=max(f[i-1][k]+sum(k,j))
           =max(f[i-1][k]+sum(1,j)-sum(1,k))
           =max(f[i-1][k]-sum(1,k))+sum(1,j)
**/
const int maxn=111;
const int maxm=11111;
int n,m,X,T;
int score[maxn][maxm];
int f[maxn][maxm];
int que[maxm],les[maxm];

int main()
{
    int head,tail;
    int sum,tmp;
    while (cin>>n>>m>>X>>T)
    {
        REP_1(i,n) REP_1(j,m)
            cin>>score[i][j];
        FOR_1(i,0,m) f[0][i]=-INF;
        f[0][X]=0;
        REP_1(i,n)
        {
            f[i][1]=f[i-1][1]+score[i][1];
            head=tail=0;
            les[0]=1;
            que[0]=f[i-1][1];
            sum=score[i][1];
            FOR_1(j,2,m)
            {
                while (head<=tail&&j-les[head]>T) head++;
                tmp=f[i-1][j]-sum;
                while (head<=tail&&que[tail]<=tmp) tail--;
                sum+=score[i][j];
                tail++;
                les[tail]=j;
                que[tail]=tmp;
                f[i][j]=que[head]+sum;
            }
            head=tail=0;
            les[0]=m;
            f[i][m]=max(f[i][m],f[i-1][m]+score[i][m]);
            que[0]=f[i-1][m];
            sum=score[i][m];
            DWN_1(j,m-1,1)
            {
                while (head<=tail&&les[head]-j>T) head++;
                tmp=f[i-1][j]-sum;
                while (head<=tail&&que[tail]<=tmp) tail--;
                sum+=score[i][j];
                tail++;
                les[tail]=j;
                que[tail]=tmp;
                f[i][j]=max(f[i][j],que[head]+sum);
            }
        }
        int ans=-INF;
        REP_1(i,m)
        {
            ans=max(ans,f[n][i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
