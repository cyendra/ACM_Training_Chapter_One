#include <iostream>
#include <cstring>
using namespace std;

const double OO=99999999.0;

int n;
double a[1111];

int f[1111],g[1111];

int ans;

int main()
{
    while (cin>>n)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        a[0]=-OO;
        a[n+1]=-OO;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if ( a[i]>a[j] && f[j]+1>f[i] )
                {
                    f[i]=f[j]+1;
                }
            }
        }
        for (int i=n;i>=1;i--)
        {
            for (int j=n+1;j>i;j--)
            {
                if ( a[i]>a[j] && g[j]+1>g[i] )
                {
                    g[i]=g[j]+1;
                }
            }
        }
        ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                ans=max( ans , f[i]+g[j] );
            }
        }
        for (int i=1;i<=n;i++)
        {
            ans=max( ans , f[i]+g[i]-1 );
        }
        ans=n-ans;
        cout<<ans<<endl;
    }
    return 0;
}
