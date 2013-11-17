#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
bool a[111][111];
int x[111],y[111];
bool vis[111]={0};

bool dfs(int u,int v)
{
    vis[u]=true;
    if (u==v) return true;
    for (int i=0;i<n;i++)
        if (a[u][i]&&!vis[i])
            if (dfs(i,v)) return true;
    return false;
}

int main()
{
    int T;
    n=0;
    memset(a,0,sizeof(a));
    cin>>T;
    while (T--)
    {
        int t;
        cin>>t;
        if (t==1)
        {
            cin>>x[n]>>y[n];
            for (int i=0;i<n;i++)
            {
                if ((x[i]<x[n]&&x[n]<y[i])||(x[i]<y[n]&&y[n]<y[i])) a[n][i]=true;
                if ((x[n]<x[i]&&x[i]<y[n])||(x[n]<y[i]&&y[i]<y[n])) a[i][n]=true;
            }
            n++;
        }
        if (t==2)
        {
            int x,y;
            cin>>x>>y;
            memset(vis,0,sizeof(vis));
            if (dfs(x-1,y-1)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
