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

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 222222

using namespace std;

int num[N];
struct Tree{
    int l,r;
    int v;
    int d;
}tree[N*4];

void push_up(int root){
    if (tree[root].d&1) tree[root].v=tree[root<<1].v|tree[root<<1|1].v;
    else                tree[root].v=tree[root<<1].v^tree[root<<1|1].v;
}

void build(int root,int l,int r){
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r){
        tree[root].v=num[l];
        tree[root].d=0;
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    tree[root].d=tree[root<<1].d+1;
    push_up(root);
}
void update(int root,int pos,int val){
    if(tree[root].l==tree[root].r){
        tree[root].v=val;
        return;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if(pos<=mid) update(root<<1,pos,val);
    else update(root<<1|1,pos,val);
    push_up(root);
}
int query(){
    return tree[1].v;
}

int main()
{
    int n,m,mn;
    int p,b;
    cin>>n>>m;
    mn=int(pow(2,n));
    for (int i=1;i<=mn;i++) cin>>num[i];
    build(1,1,mn);
    while (m--){
        cin>>p>>b;
        update(1,p,b);
        cout<<query()<<endl;
    }
    return 0;
}
