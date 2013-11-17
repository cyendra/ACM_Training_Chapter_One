#include <iostream>
#include <cstring>
using namespace std;

int n,m;
int a[111][111];
int f[111][111];

int main()
{
    while (cin>>n>>m)
    {
        if (n==0&&m==0) break;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=m;j++)
            {
                f[i][j]=f[i-1][j];
                for (int k=1;k<=j;k++)
                {
                    f[i][j]=max(f[i][j],f[i-1][j-k]+a[i][k]);
                }
            }
        }
        cout<<f[n][m]<<endl;
    }
    return 0;
}
