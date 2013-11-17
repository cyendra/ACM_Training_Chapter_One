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

struct POINT{
    int x;
    int y;
}st[11];

vector<int> vx;
vector<int> vy;

int main()
{
    int n;
    bool fd;
    n=8;
    vx.clear();
    vy.clear();
    REP(i,n)
    {
        cin>>st[i].x>>st[i].y;
        fd=false;
        REP(j,sz(vx))
        {
            if (vx[j]==st[i].x)
            {
                fd=true;
                break;
            }
        }
        if (!fd) vx.pb(st[i].x);
        fd=false;
        REP(j,sz(vy))
        {
            if (vy[j]==st[i].y)
            {
                fd=true;
                break;
            }
        }
        if (!fd) vy.pb(st[i].y);
    }
    if (sz(vx)!=3||sz(vy)!=3) cout<<"ugly"<<endl;
    else
    {
        sort(vx.begin(),vx.end());
        sort(vy.begin(),vy.end());
        REP(i,sz(vx))
        {
            REP(j,sz(vy))
            {
                if (i==1&&j==1) continue;
                fd=false;
                REP(k,n)
                {
                    if (st[k].x==vx[i]&&st[k].y==vy[j])
                    {
                        fd=true;
                        break;
                    }
                }
                if (!fd) break;
            }
            if (!fd) break;
        }
        if (fd) cout<<"respectable"<<endl;
        else cout<<"ugly"<<endl;
    }
    return 0;
}
