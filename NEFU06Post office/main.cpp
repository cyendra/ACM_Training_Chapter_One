#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long a[1111];
long long f[1111];
long long g[1111];
int n;
int q;


int main()
{
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));

        for (int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
            f[i]=f[i-1]+a[i];
        }
        for (int i=n;i>=1;i--)
        {
            g[i]=g[i+1]+a[i];
        }
        scanf("%d",&q);
        while (q--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int mid=(x+y)/2;
            long long ans=(a[mid]*(mid-x)-(f[mid-1]-f[x-1]))+((g[mid+1]-g[y+1])-a[mid]*(y-mid));
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

