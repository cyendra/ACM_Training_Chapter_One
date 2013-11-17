#include <iostream>
#include <cstring>
#include <algorithm>
#define OO 999999
using namespace std;

int a[2010];
int f[2010][2010];
int n,k;

int main()
{
    while ( cin >> n >> k )
    {
        a[0]=0;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        memset(f,0,sizeof(f));
        for (int i=2;i<=n;i++)
        {
            for (int j=1;j<=k&&j*2<=i;j++)
            {
                if ( j*2==i )
                {
                    f[i][j]=f[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
                }
                else
                {
                    f[i][j]=f[i-1][j];
                    if ( f[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1])<f[i][j] )
                    {
                        f[i][j]=f[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]);
                    }
                }
            }
        }
        cout << f[n][k]<<endl;
    }
    return 0;
}
