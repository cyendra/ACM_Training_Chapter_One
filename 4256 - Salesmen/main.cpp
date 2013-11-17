#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=555;
const int OO=1e9;

int T;
int n1,n2;
bool path[maxn][maxn];
int f[maxn][maxn];
int a[maxn];
int n;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        memset(path,0,sizeof(path));
        memset(f,-1,sizeof(f));
        scanf("%d%d",&n1,&n2);
        for (int i=1;i<=n2;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            path[x][y]=1;
            path[y][x]=1;
        }
        for (int i=1;i<=n1;i++) path[i][i]=1;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=0;i<=n1;i++)
        {
            f[0][i]=0;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n1;j++)
            {
                for (int k=1;k<=n1;k++)
                {
                    if (a[i]==j)
                    {
                        if (path[k][j] && f[i-1][k]!=-1 && (f[i-1][k]<f[i][j]||f[i][j]==-1))
                            f[i][j]=f[i-1][k];
                    }
                    else
                    {
                        if (path[k][j] && f[i-1][k]!=-1 && (f[i-1][k]+1<f[i][j]||f[i][j]==-1))
                            f[i][j]=f[i-1][k]+1;
                    }
                }
            }
        }
        //for (int i=1;i<=n;i++)for (int j=1;j<=n1;j++)cerr<<f[i][j]<<" ";cerr<<endl;
        int ans=OO;
        for (int i=1;i<=n1;i++)
            if (f[n][i]<ans) ans=f[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
