#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int direct[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };

int f[111][111];
int a[111][111];
char name[111];
int n,m;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    else return false;
}

void dfs(int x,int y,int deep)
{
    if (f[x][y]>=deep) return;
    f[x][y]=deep;
    for (int i=0;i<4;i++)
    {
        int dx=x+direct[i][0];
        int dy=y+direct[i][1];
        if (check(dx,dy)&&a[dx][dy]<a[x][y]&&f[dx][dy]<deep+1)
        {
            dfs(dx,dy,deep+1);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        scanf("%s%d%d",name,&n,&m);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (f[i][j]==0)
                {
                    dfs(i,j,1);
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (f[i][j]>ans) ans=f[i][j];
            }
        }
        printf("%s: %d\n",name,ans);
    }
    return 0;
}
