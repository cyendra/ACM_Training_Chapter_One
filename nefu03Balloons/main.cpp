#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int direct1[8][2]={ {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1} };
const int direct2[4][2]={ {0,1},{0,-1},{1,0},{-1,0} };

char a[211][211];
int c[211][211];
int n;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs1(int x,int y,int clr)
{
    int dx,dy;
    c[x][y]=clr;
    for (int i=0;i<8;i++)
    {
        dx=x+direct1[i][0];
        dy=y+direct1[i][1];
        if (check(dx,dy)&&a[dx][dy]=='1'&&c[dx][dy]==0)
        {
            dfs1(dx,dy,clr);
        }
    }
}

void dfs2(int x,int y,int clr)
{
    int dx,dy;
    c[x][y]=clr;
    for (int i=0;i<4;i++)
    {
        dx=x+direct2[i][0];
        dy=y+direct2[i][1];
        if (check(dx,dy)&&a[dx][dy]=='1'&&c[dx][dy]==0)
        {
            dfs2(dx,dy,clr);
        }
    }
}

int main()
{
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));

        for (int i=1;i<=n;i++) scanf("%s",a[i]+1);

        int ans1=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (c[i][j]==0&&a[i][j]=='1')
                {
                    ans1++;
                    dfs1(i,j,ans1);
                }
            }
        }

        memset(c,0,sizeof(c));
        int ans2=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (c[i][j]==0&&a[i][j]=='1')
                {
                    ans2++;
                    dfs2(i,j,ans2);
                }
            }
        }

        printf("Case %d: %d %d\n\n",cnt++,ans2,ans1);
    }
    return 0;
}
