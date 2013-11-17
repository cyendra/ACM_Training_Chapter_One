
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=32;
const long long INF=(1LL<<62);
int A,B,C;

long long submax(long long num[maxn])
{
    long long ans=num[1];
    long long f=num[1];
    for (int i=2;i<=C;i++)
    {
        f=max(num[i]+f,num[i]);
        ans=max(ans,f);
    }
    return ans;
}

long long submax2d(long long num[maxn][maxn])
{
    long long ret,ans=-INF;
    long long a[maxn];
    for (int l=1;l<=B;l++)
    {
        memset(a,0,sizeof(a));
        for (int r=l;r<=B;r++)
        {
            for (int i=1;i<=C;i++)
            {
                a[i]+=num[r][i];
            }
            ret=submax(a);
            if (ret>ans) ans=ret;
        }
    }
    return ans;
}

long long submax3d(long long num[maxn][maxn][maxn])
{
    long long ret,ans=-INF;
    long long a[maxn][maxn];
    for (int l=1;l<=A;l++)
    {
        memset(a,0,sizeof(a));
        for (int r=l;r<=A;r++)
        {
            for (int i=1;i<=B;i++)
            {
                for (int j=1;j<=C;j++)
                {
                    a[i][j]+=num[r][i][j];
                }
            }
            ret=submax2d(a);
            if (ret>ans) ans=ret;
        }
    }
    return ans;
}

int main()
{
    int T;
    long long a[maxn][maxn][maxn];
    long long ans;
    //freopen("abc.in","r",stdin);
    //freopen("abc.out","w",stdout);
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d%d",&A,&B,&C);
        for (int i=1;i<=A;i++)
        {
            for (int j=1;j<=B;j++)
            {
                for (int k=1;k<=C;k++)
                {
                    scanf("%lld",&a[i][j][k]);
                }
            }
        }
        ans=submax3d(a);
        printf("%lld\n",ans);
        if (T) printf("\n");
    }
    return 0;
}

/*
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

const LL INF = 1LL<<60;
int A, B, C;
LL sumz[25][25][25]; // 平面上[1,1]到[i][j]在高度为k时的区域前缀和

LL get(int x1, int y1, int x2, int y2, int z) {
    return sumz[x2][y2][z] - sumz[x1-1][y2][z] - sumz[x2][y1-1][z] + sumz[x1-1][y1-1][z];
}

void solve() {
    // 需要枚举平面上的二维组合
    LL ret = -INF;
    LL Min, s;
    for (int i = 1; i <= A; ++i) {
        for (int j = i; j <= A; ++j) {
            for (int k = 1; k <= B; ++k) {
                for (int h = k; h <= B; ++h) {
                    Min = 0;
                    for (int p = 1; p <= C; ++p) {
                        s = get(i, k, j, h, p);
                        ret = max(ret, s - Min);
                        if (s < Min) Min = s;
                    }
                }
            }
        }
    }
    printf("%I64d\n", ret);
}

int main() {
    freopen("abc.in","r",stdin);
    freopen("abc2.out","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &A, &B, &C);
        LL tot, x;
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                tot = 0;
                for (int k = 1; k <= C; ++k) {
                    scanf("%I64d", &x);
                    tot += x;
                    sumz[i][j][k] = sumz[i-1][j][k] + sumz[i][j-1][k] - sumz[i-1][j-1][k] + tot;
                }
            }
        }
        solve();
        if (T) puts("");
    }
    return 0;
}
*/

/*
# include <iostream>
# include <cstring>
# include <algorithm>
# define rep(x, s, t) for (int x = (s); x <= (t); ++x )

using namespace std;

const int maxn = 30;
const long long INF = 1LL<<60;
int a, b, c;
long long S[maxn][maxn][maxn];

inline void expand(int i, int&b0, int& b1, int &b2)
{
    b0 = i&1; i >>= 1;
    b1 = i&1; i >>= 1;
    b2 = i&1;
}

inline int sign(int b0, int b1, int b2)
{
    return (b0 + b1 + b2) % 2 == 1 ? 1 : -1;
}

long long sum(int x1, int x2, int y1, int y2, int z1, int z2)
{
    int dx = x2-x1+1, dy = y2-y1+1, dz = z2-z1+1;
    long long s = 0;
    rep(i, 0, 7)
    {
        int b0, b1, b2;
        expand(i, b0, b1, b2);
        s -= S[x2 - b0*dx][y2 - b1*dy][z2 - b2*dz] * sign(b0, b1, b2);
    }
    return s;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int b0, b1, b2;
        cin >> a >> b >> c;
        memset(S, 0, sizeof S);
        rep(x, 1, a) rep(y, 1, b) rep(z, 1, c) cin >> S[x][y][z];
        rep(x, 1, a) rep(y, 1, b) rep(z, 1, c)
            rep(i, 1, 7)
            {
                expand(i, b0, b1, b2);
                S[x][y][z] += S[x-b0][y-b1][z-b2] * sign(b0, b1, b2);
            }

        long long ans = -INF;

        rep(x1, 1, a) rep(x2, x1, a) rep(y1, 1, b) rep(y2, y1, b)
        {
            long long M = 0;
            rep(z, 1, c)
            {
                long long s = sum(x1, x2, y1, y2, 1, z);
                ans = max(ans, s - M);
                M = min(M, s);
            }
        }
        cout << ans << endl;
        if (T) cout << endl;
    }
    return 0;
}
*/
