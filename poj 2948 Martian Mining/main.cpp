#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int nor[555][555];
int wes[555][555];
int fnor[555][555];
int fwes[555][555];

int n,m;
int ans;

int main()
{
    while ( scanf("%d%d",&n,&m)!=EOF )
    {
        if (n==0&&m==0) break;
        memset(nor,0,sizeof(nor));
        memset(wes,0,sizeof(wes));
        memset(fnor,0,sizeof(fnor));
        memset(fwes,0,sizeof(fwes));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&wes[i][j]);
                wes[i][j]+=wes[i][j-1];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&nor[i][j]);
                nor[i][j]+=nor[i-1][j];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                fnor[i][j]=nor[i][j]+max( fnor[i][j-1] , fwes[i][j-1] );
                fwes[i][j]=wes[i][j]+max( fwes[i-1][j] , fnor[i-1][j] );
            }
        }
        ans=max( fnor[n][m] ,fwes[n][m] );
        printf("%d\n",ans);
    }
    return 0;
}
