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

const int maxn=11111;
const int maxm=2111111;
int n,m;
struct EDGENODE{
    int to;
    int next;
};

struct TWO_SAT{
    int head[maxn*2];
    EDGENODE edges[maxm*2];
    int edge;
    int n;
    bool mark[maxn*2];
    int S[maxn*2],c;
    void init(int n){
        this->n=n;
        clr(mark,0);
        clr(head,-1);
        edge=0;
    }
    void addedge(int u,int v){
        edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    // x = xval or y = yval
    void add_clause(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x^1,y);
        addedge(y^1,x);
    }
    void add_con(int x,int xval){
        x=x*2+xval;
        addedge(x^1,x);
    }
    bool dfs(int x){
        if (mark[x^1]) return false;
        if (mark[x]) return true;
        mark[x]=true;
        S[c++]=x;
        for (int i=head[x];i!=-1;i=edges[i].next)
            if (!dfs(edges[i].to)) return false;
        return true;
    }
    bool solve(){
        for (int i=0;i<n*2;i+=2)
            if (!mark[i]&&!mark[i+1]){
                c=0;
                if (!dfs(i)){
                    while (c>0) mark[S[--c]]=false;
                    if (!dfs(i+1)) return false;
                }
            }
        return true;
    }
}TwoSAT;
int main()
{
    int a,b,c;
    char s[4];
    while (~scanf("%d%d",&n,&m))
    {
        TwoSAT.init(n);
        REP(i,m)
        {
            scanf("%d%d%d%s",&a,&b,&c,s);
            /*
            if (!strcmp(s,"AND")){
                if (c==1){
                    TwoSAT.add_self(a,1,a,0);
                    TwoSAT.add_self(b,1,b,0);
                }else if (c==0){
                    TwoSAT.add_self(a,0,b,1);
                    TwoSAT.add_self(b,0,a,1);
                }
            }
            if (!strcmp(s,"OR")){
                if (c==1){
                    TwoSAT.add_self(a,1,b,0);
                    TwoSAT.add_self(b,1,a,0);
                }else if (c==0){
                    TwoSAT.add_self(a,0,a,1);
                    TwoSAT.add_self(b,0,b,1);
                }
            }
            if (!strcmp(s,"XOR")){
                if (c==1){
                    TwoSAT.add_self(a,0,b,1);
                    TwoSAT.add_self(b,0,a,1);
                    TwoSAT.add_self(a,1,b,0);
                    TwoSAT.add_self(b,1,a,0);
                }else if (c==0){
                    TwoSAT.add_self(a,0,b,0);
                    TwoSAT.add_self(b,0,a,0);
                    TwoSAT.add_self(a,1,b,1);
                    TwoSAT.add_self(b,1,a,1);
                }
            }*/
            if (!strcmp(s,"AND")){
                if (c==1){
                    TwoSAT.add_con(a,1);
                    TwoSAT.add_con(b,1);
                }else if (c==0){
                    TwoSAT.add_clause(a,0,b,0);
                }
            }
            if (!strcmp(s,"OR")){
                if (c==1){
                    TwoSAT.add_clause(a,1,b,1);
                }else if (c==0){
                    TwoSAT.add_con(a,0);
                    TwoSAT.add_con(b,0);
                }
            }
            if (!strcmp(s,"XOR")){
                if (c==1){
                    TwoSAT.add_clause(a,1,b,1);
                    TwoSAT.add_clause(a,0,b,0);
                }else if (c==0){
                    TwoSAT.add_clause(a,1,b,0);
                    TwoSAT.add_clause(a,0,b,1);
                }
            }
        }
        if (TwoSAT.solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}
