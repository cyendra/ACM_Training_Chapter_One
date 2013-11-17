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

const int MAXN=255111;
struct SegmentTree{
    int num[MAXN];
    struct Tree{
        int l;
        int r;
        int min;
    };
    Tree tree[MAXN*4];
    void push_up(int root){
        tree[root].min=min(tree[root<<1].min,tree[root<<1|1].min);
    }
    void build(int root,int l,int r){
        tree[root].l=l;
        tree[root].r=r;
        if(tree[root].l==tree[root].r){
            tree[root].min=num[l];
            return;
        }
        int mid=(l+r)/2;
        build(root<<1,l,mid);
        build(root<<1|1,mid+1,r);
        push_up(root);
    }
    void update(int root,int pos,int val){
        if(tree[root].l==tree[root].r){
            tree[root].min=val;
            return;
        }
        int mid=(tree[root].l+tree[root].r)/2;
        if(pos<=mid) update(root<<1,pos,val);
        else update(root<<1|1,pos,val);
        push_up(root);
    }
    int query(int root,int L,int R){
        if(L<=tree[root].l&&R>=tree[root].r) return tree[root].min;
        int mid=(tree[root].l+tree[root].r)/2,ret=INF;
        if(L<=mid) ret=min(ret,query(root<<1,L,R));
        if(R>mid) ret=min(ret,query(root<<1|1,L,R));
        return ret;
    }
    void init(int n,int d){
        for (int i=1;i<=n;i++) num[i]=d;
        build(1,1,n);
    }
}D;
const int maxn=255000;
const int maxm=750000;
int n,m;
int S[maxn];
int T[maxm];
int f[maxm];
/**
    f[0][1]=0
    f[0][j]=INF (j>1)
    f[i][j]=f[i-1][j] (j!=T(i-1))
           =min(f[i-1][j],min{f[i][j']|Si<=j'<=Ti}+1) (j==T(i-1))
    f[1]=0
    f[j]=INF (j>1)
    f[Ti]=min(f[Ti],min{Si<=j'<=Ti}+1)
**/
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for (int i=1;i<=m;i++) scanf("%d%d",&S[i],&T[i]);
        for (int i=0;i<=n;i++) f[i]=INF;
        D.init(n,INF);
        f[1]=0;
        D.update(1,1,0);
        for (int i=1;i<=m;i++){
            int v=min(f[T[i]],D.query(1,S[i],T[i])+1);
            f[T[i]]=v;
            D.update(1,T[i],v);
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
