#include <iostream>
#include <cstring>
using namespace std;

int a[100][100];
bool u[100];
int n,x,y,len;

void dfs(int k)
{
    u[k] = true;
    for (int i = 1; i <= n; i++)
    {
        if ((a[k][i]) && (!u[i])) dfs(i);
    }
}

int main()
{
    while (cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(u,false,sizeof(u));
        len=n*(n-1)/2-1;
        for (int i=1; i<=len; i++)
        {
            cin>>x>>y;
            a[x][y]=1;
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=i+1; j<=n; j++)
            {
                if (a[i][j]==0&&a[j][i]==0)
                {
                    x=i;
                    y=j;
                }
            }
        }
        dfs(x);
        if (u[y]) cout<<x<<" "<<y<<endl;
        else cout<<y<<" "<<x<<endl;
    }
    return 0;
}
