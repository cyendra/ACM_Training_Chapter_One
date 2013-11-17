#include <iostream>
#include <cstring>

using namespace std;

int f[1111];
int a[1111];
int n;
int ans;

const int OO=9999999;

int main()
{
    while (cin>>n)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        ans=-OO;
        a[0]=-OO;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<i;j++)
            {
                if ( a[i]>a[j] && f[i]<f[j]+1 )
                {
                    f[i]=f[j]+1;
                }
            }
            ans=max(ans,f[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
