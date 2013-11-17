#include <iostream>

using namespace std;

int a[1111]={0};
int f[1111]={0};
int g[1111]={0};
int n;

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]>=a[i-1])
        {
            f[i]=f[i-1]+1;
        }
        else
        {
            f[i]=1;
        }
    }
    for (int i=n;i>=1;i--)
    {
        if (a[i]>=a[i+1])
        {
            g[i]=g[i+1]+1;
        }
        else
        {
            g[i]=1;
        }
    }
    int ans=0;
    int ret;
    for (int i=1;i<=n;i++)
    {
        ret=f[i]+g[i]-1;
        if (ret>ans)
        {
            ans=ret;
        }
    }
    cout<<ans<<endl;
    return 0;
}
