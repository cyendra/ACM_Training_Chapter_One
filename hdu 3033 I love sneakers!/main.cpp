#include <iostream>
#include <cstring>

using namespace std;

int n,m,K;
int k,b,c;
int a[11][111];
int v[11][111];
int t[11];
int f[11][111000];
int s;
const int OO=-99999999;

int main()
{
    while (cin>>n>>m>>K)
    {
        s=0;
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(t,0,sizeof(t));
        memset(f,0,sizeof(f));
        for (int i=0; i<n; i++)
        {
            cin>>k>>b>>c;
            t[k]++;
            a[ k ][ t[k] ]=b;
            v[ k ][ t[k] ]=c;
        }
        for (int i=0;i<=K;i++)
        {
            for (int j=0;j<=m;j++)
            {
                f[i][j]=OO;
            }
        }
        f[0][0]=0;
        for (int i=1; i<=K; i++)
        {
            if ( t[i]>0 ) s++;
            for (int k=1;k<=t[i];k++)
            {
                for (int j=m;j>=a[i][k];j--)
                {
                    if (k>1) f[i][j]=max(f[i][j],f[i][j-a[i][k]]+v[i][k]);
                    f[i][j]=max(f[i][j],f[i-1][j-a[i][k]]+v[i][k]);
                }
            }
        }
        int ans=-1;
        for (int i=0;i<=m;i++)
        {
            ans=max(ans,f[K][i]);
        }
        if (s==K&&ans>=0) cout<<ans<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}
