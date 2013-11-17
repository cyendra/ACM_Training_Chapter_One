/*
#include <iostream>

using namespace std;

int a[111][111];
int f[111][111];
int n,c;

int main()
{
    cin>>c;
    while (c--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                cin>>a[i][j];
                f[i][j]=0;
            }
        }
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
            {
                if ( i==1 ) f[i][j]=a[i][j];
                else if ( j==1 ) f[i][j]=f[i-1][j]+a[i][j];
                else if ( j==i ) f[i][j]=f[i-1][j-1]+a[i][j];
                else f[i][j]=max( f[i-1][j] , f[i-1][j-1] )+a[i][j];
            }
        int ans=0;
        for (int i=1;i<=n;i++) ans=max( ans , f[n][i] );
        cout<<ans<<endl;
    }
    return 0;
}
*/
/*
#include <cstdio>
#include <iostream>
using namespace std;
int n,ans;
int a[1111],f[1111];
int main()
{
    while (cin>>n)
    {
        if (n==0) break;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            f[i]=0;
        }
        a[0]=0;
        f[n+1]=0;
        for (int i=1;i<=n;i++)
            for (int k=0;k<i;k++)
                if ( a[i]>a[k] && f[i]<f[k]+a[i] )
                    f[i]=f[k]+a[i];
        for (int i=1;i<=n;i++)
            if (f[i]>f[n+1]) f[n+1]=f[i];
        cout<<ans<<endl;
    }
    return 0;
}
*/

for (i=0;i<=n;i++)
    for (j=0;j<=v;j++)
        f[i][j]=0;

for (i=1;i<=n;i++)
    for (j=c[i];j<=v;j++)
        f[i][j]=max(f[i-1][j], f[i-1][j-c[i]]+w[i]);

int fib(int n)
{
    if (n = 0 || n = 1) return 1;
    else return fib(n − 1) + fib(n − 2);
}

