#include <iostream>
#include <cstring>
using namespace std;

int f[400][400];
int a[400][400];
int n;

int main()
{
    while (cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                cin>>a[i][j];
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                if ( i==1 )
                {
                    f[i][j]=a[i][j];
                }
                else if ( j==1 )
                {
                    f[i][j]=f[i-1][j]+a[i][j];
                }
                else if ( j==i )
                {
                    f[i][j]=f[i-1][j-1]+a[i][j];
                }
                else
                {
                    f[i][j]=max( f[i-1][j-1] , f[i-1][j] )+a[i][j];
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            ans=max( ans , f[n][i] );
        }
        cout<<ans<<endl;
    }
    return 0;
}
