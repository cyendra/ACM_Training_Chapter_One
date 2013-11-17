#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[111];
char b[111];
long long f[111][111];
long long g[111][111];
int n,m;
long long ans;

int main()
{
    int T;
    cin>>T;
    getchar();
    for (int cnt=1;cnt<=T;cnt++)
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        ans=0;
        gets(a+1);
        gets(b+1);
        n=strlen(a+1);
        m=strlen(b+1);
        for (int i=0;i<=n;i++) g[i][0]=1;
        for (int i=0;i<=m;i++) g[0][i]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i]==b[j])
                {
                    f[i][j]=f[i-1][j-1]+1;
                    g[i][j]=g[i-1][j-1];
                }
                else
                {
                    if (f[i-1][j]>f[i][j-1])
                    {
                        f[i][j]=f[i-1][j];
                        g[i][j]=g[i-1][j];
                    }
                    else if (f[i-1][j]<f[i][j-1])
                    {
                        f[i][j]=f[i][j-1];
                        g[i][j]=g[i][j-1];
                    }
                    else
                    {
                        f[i][j]=f[i][j-1];
                        g[i][j]=g[i-1][j]+g[i][j-1];
                    }
                }
            }
        }
        ans=n+m-f[n][m];
        cout<<"Case #"<<cnt<<": "<<ans<<" "<<g[n][m]<<endl;
    }
    return 0;
}
