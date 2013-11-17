#include <iostream>
#include <cstring>

using namespace std;

typedef long long int LL;

const LL OO=999999999999999L;

LL f[2000][2000];
LL n;
int c[2000],t[2000];
LL ans;

LL dp(int i,int j)
{
    if (j>=n) return 0;
    if (i==n) return OO;
    LL &ret=f[i][j];
    if (f[i][j]!=-1) return ret;
    ret=min( dp(i+1,j) , c[i]+dp(i+1,j+t[i]) );
    return ret;
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>t[i]>>c[i];
        t[i]++;
    }
    memset(f,-1,sizeof(f));
    /*
    int p;
    f[0][0]=0;
    for (int i=0;i<=n-2;i++)
    {
        for (int j=0;j<=n-1;j++)
        {
            if ( f[i+1][j]==-1 )
            {
                f[i+1][j]=f[i][j];
            }
            else if ( f[i][j]<f[i+1][j] )
            {
                f[i+1][j]=f[i][j];
            }
            p=j+t[i];
            if ( p>=n ) p=n-1;
            if ( f[i+1][p]==-1 )
            {
                f[i+1][p]=f[i][j]+c[i];
            }
            else if ( f[i][j]+c[i]<f[i+1][p] )
            {
                f[i+1][p]=f[i][j]+c[i];
            }
        }
    }
    ans=f[n-1][n-1];
    */
    ans=dp(0,0);
    cout<<ans<<endl;
    return 0;
}
