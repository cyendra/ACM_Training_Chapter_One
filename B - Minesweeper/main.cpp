#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int direct[8][2]={ {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1} };

char s[111][111];
int f[111][111];
int n,m;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

int main()
{
    int cnt=0;
    while (~scanf("%d%d",&n,&m))
    {
        if (n==0&&m==0) break;
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (s[i][j]=='*')
                {
                    for (int k=0;k<8;k++)
                    {
                        int x=i+direct[k][0];
                        int y=j+direct[k][1];
                        if (check(x,y)) f[x][y]++;
                    }
                }
            }
        }
        if (cnt>0) puts("");
        printf("Field #%d:\n",++cnt);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (s[i][j]=='*') printf("*");
                else printf("%d",f[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
