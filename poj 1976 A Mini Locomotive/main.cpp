#include <iostream>
#include <cstring>
using namespace std;

int T,n,m,k;
int a[6000];
int s[6000];
int f[6000][4];

int main()
{
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
        }
        cin>>m;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=3;j++)
            {
                k=i-m;
                if (k<0) k=0;
                f[i][j]=max(f[i-1][j],f[k][j-1]+s[i]-s[k]);
            }
        }
        cout<<f[n][3]<<endl;
    }
    return 0;
}
