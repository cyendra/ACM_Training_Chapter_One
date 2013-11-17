#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int direct[8][2]={ {0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

int n,m;
char a[111][111];
int c[111][111];
int cl;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    else return false;
}

void dfs(int x,int y,int col)
{
    if (c[x][y]!=0||a[x][y]!='@') return;
    c[x][y]=col;
    for (int i=0;i<8;i++)
    {
        int dx=x+direct[i][0];
        int dy=y+direct[i][1];
        if (check(dx,dy)&&a[dx][dy]=='@'&&c[dx][dy]==0)
        {
            dfs(dx,dy,col);
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",a[i]+1);
        }
        cl=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='@'&&c[i][j]==0)
                {
                    cl++;
                    dfs(i,j,cl);
                }
            }
        }
        printf("%d\n",cl);
    }
    return 0;
}
