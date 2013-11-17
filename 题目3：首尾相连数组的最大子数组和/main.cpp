#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn=410000;
int n,m,l[maxn],r[maxn],sum;
int a[maxn];
int f[maxn];
int ans;
int main()
{
    while (~scanf("%d",&n))
    {
        ans=0;
        sum=0;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(r,0,sizeof(r));
        memset(l,0,sizeof(l));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;i++)
        {
            if (f[i-1]+a[i]>a[i]) f[i]=f[i-1]+a[i];
            else f[i]=a[i];
            ans=max(ans,f[i]);
        }
        sum=0;
        for (int i=1;i<=n;i++)
        {
            sum+=a[i];
            if (sum>l[i-1]) l[i]=sum;
            else l[i]=l[i-1];
        }
        sum=0;
        for (int i=n;i>=1;i--)
        {
            sum+=a[i];
            if (sum>r[i+1]) r[i]=sum;
            else r[i]=r[i+1];
        }
        for (int i=1;i<n;i++)
        {
            if (l[i]+r[i+1]>ans) ans=l[i]+r[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
