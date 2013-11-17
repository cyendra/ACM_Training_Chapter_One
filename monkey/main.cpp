#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,t;

int a[111][111];
int f[111][111][111];

int dfs(int jp,int time,int place)
{
    if (f[jp][time][place]!=-1) return f[jp][time][place];
    int ret=0;
    if (time<m) ret=dfs(jp,time+1,place);
    if (place+1<=n&&jp>0&&time<m)
    {
        ret=max( ret, dfs(jp-1,time+1,place+1) );
    }
    if (place-1>=1&&jp>0&&time<m)
    {
        ret=max( ret, dfs(jp-1,time+1,place-1) );
    }
    f[jp][time][place]=ret+a[time][place];
    return f[jp][time][place];
}

int main()
{
    int cnt=0;
    int maxt;
    while (cin>>n>>m>>t)
    {
        cnt++;
        maxt=0;
        memset(f,-1,sizeof(f));
        memset(a,0,sizeof(a));
        for (int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            a[i][x]+=y;
        }
        int ans=dfs(t,0,1);

        cout<<"Scenario #"<<cnt<<endl;
        cout<<ans<<endl<<endl;
    }
    return 0;
}
