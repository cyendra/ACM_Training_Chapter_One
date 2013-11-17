#include <iostream>
#include <cstring>
using namespace std;

int a[600][600];
bool v[600];
int d[600];

int n,K;

bool dfs(int p)
{
    int t;
    for (int i=1;i<=n;i++)
    {
        if (a[i][p]&&!v[i])
        {
            v[i]=true;
            t=d[i];
            d[i]=p;
            if (t==0||dfs(t))
            {
                return true;
            }
            d[i]=t;
        }
    }
    return false;
}

int main()
{
    int ans,x,y;
    while (cin>>n>>K)
    {
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        ans=0;
        for (int i=1;i<=K;i++)
        {
            cin>>x>>y;
            a[x][y]=1;
        }
        for (int i=1;i<=n;i++)
        {
            memset(v,0,sizeof(v));
            if (dfs(i))
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
