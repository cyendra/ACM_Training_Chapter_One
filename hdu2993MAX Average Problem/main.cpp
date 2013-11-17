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
const int maxn=111111;

int a[maxn];
int sum[maxn];
int que[maxn];
int head,tail;

int getin()
{
    char ch=' ';
    while (ch<'0'||ch>'9') ch=getchar();
    int x=0;
    while (ch>='0'&&ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x;
}

double getup(int i,int j)
{
    return sum[i]-sum[j];
}
int getdown(int i,int j)
{
    return i-j;
}
long long cross(int a,int b,int c)
{
    long long x1=b-a;
    long long y1=sum[b]-sum[a];
    long long x2=c-b;
    long long y2=sum[c]-sum[b];
    return x1*y2-y1*x2;
}
int dbsearch(int l,int r,int i)
{
    while (l<r)
    {
        int mid=(l+r)/2;
        if (cross(que[mid],que[mid+1],i)<0) r=mid;
        else l=mid+1;
    }
    return l;
}

int main()
{
    int n,k;
    while (~scanf("%d%d",&n,&k))
    {
        sum[0]=0;
        REP_1(i,n)
        {
            a[i]=getin();
            sum[i]=sum[i-1]+a[i];
        }
        head=tail=0;
        que[tail++]=0;
        double ans=0;
        FOR_1(i,k,n)
        {
            int j=i-k;
            while (head+1<tail&&cross(que[tail-2],que[tail-1],j)<0) tail--;
            que[tail++]=j;
            int tmp=dbsearch(0,tail-1,i);
            double f=double(sum[i]-sum[que[tmp]])/(i-que[tmp]);
            ans=max(ans,f);
        }
        printf("%0.2f\n",ans);
    }
    return 0;
}
