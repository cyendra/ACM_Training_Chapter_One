#include <iostream>
#include <cstring>

using namespace std;

int T;
int n;
int a[111],v[111];
int s[111];
int f[111];

int main()
{
    cin>>T;
    while (T--)
    {
        memset(s,0,sizeof(s));
        memset(a,0,sizeof(a));
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i]>>v[i];
            s[i]=s[i-1]+a[i];
        }
        a[0]=0;
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            f[i]=f[i-1]+(a[i]+10)*v[i];
            for (int j=0;j<i;j++)
            {
                f[i]=min( f[i] , f[j]+(s[i]-s[j]+10)*v[i] );
            }
        }
        cout<<f[n]<<endl;
    }
    return 0;
}
