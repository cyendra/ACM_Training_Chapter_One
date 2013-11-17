#include <iostream>
#include <cstring>

using namespace std;

int a[111][111];
int n,x,y,t,p,ans1,ans2;
int loop[111];
bool v[111];

void dfs(int e)
{
    v[e]=true;
    loop[p++]=e;
    for (int i=1;i<=n;i++)
    {
        if (!v[i]&&(a[e][i]>0||a[i][e]>0))
        {
            dfs(i);
        }
    }
}

int main()
{
    memset(a,0,sizeof(a));
    memset(v,0,sizeof(v));
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y>>t;
        a[x][y]=t;
    }
    p=0;
    dfs(1);
    loop[p]=1;
    ans1=0;
    ans2=0;
    for (int i=0;i<p;i++) ans1+=a[ loop[i] ][ loop[i+1] ];
    for (int i=p;i>=1;i--) ans2+=a[ loop[i] ][ loop[i-1] ];
    cout<<min(ans1,ans2)<<endl;
    return 0;
}
