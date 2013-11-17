#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int T;
int n,m,l;
int a[1111];
int v[1111];
int f[1111][1111];
const int OO=9999999;

int main()
{
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        cin>>n>>m>>l;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i]>>v[i];
        }
        for (int i=0;i<=m;i++)
        {
            for (int j=0;j<=l;j++)
            {
                f[i][j]=-OO;
            }
        }
        f[0][0]=0;
        f[m][l]=0;
        for (int k=1;k<=n;k++)
        {
            for (int i=m;i>=1;i--)
            {
                for (int j=a[k];j<=l;j++)
                {
                    f[i][j]=max( f[i][j] , f[i-1][j-a[k]]+v[k] );
                }
            }
        }
        for(int i=0;i<l;++i)
            f[m][l]=max(f[m][l],f[m][i]);
        /*
        int ans=0;
        for (int i=0;i<=l;i++)
        {
            ans=max( ans ,f[m][i] );
        }
        cout<<ans<<endl;
        */
        cout<<f[m][l]<<endl;
    }
    return 0;
}
