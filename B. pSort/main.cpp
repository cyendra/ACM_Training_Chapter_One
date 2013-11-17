#include <iostream>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define max_int       INT_MAX / 2
#define max_long      0xFFFFFFFFFFFFFFFLL / 2
#define two(a)        (1 << (a))
#define eps           1e-6
#define FF(i, a, b)   for (int i = (a); i <= (b); i++)
#define FFD(i, a, b)  for (int i = (a); i >= (b); i--)

const int OO=1e9;
const int INF=1e9;

int n;

vector<int>a[111];
int p[111];
int f[111];
bool g[111][111];
bool ok;

bool dfs(int bg,int u,int ed)
{
    g[bg][u]=true;
    if (u==ed) return true;
    int len=a[u].size();
    int v;
    FF(i, 0, len-1)
    {
        v=a[u][i];
        if (!g[bg][v])
        {
            if (dfs(bg,v,ed)) return true;
        }
    }
    return false;
}

int main()
{
    memset(g,0,sizeof(g));
    cin>>n;
    FF(i, 1, n)
    {
        cin>>p[i];
    }
    FF(i, 1, n)
    {
        cin>>f[i];
        if (i+f[i]<=n)
        {
            a[i].push_back(i+f[i]);
            a[i+f[i]].push_back(i);
        }

        if (i-f[i]>=1)
        {
            a[i].push_back(i-f[i]);
            a[i-f[i]].push_back(i);
        }
    }
    ok=true;
    FF(i ,1, n)
    {
        if (!dfs(i,i,p[i]))
        {
            ok=false;
            break;
        }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}











