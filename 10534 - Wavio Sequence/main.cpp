#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int OO=1e9;

int a[11111];
int b[11111];
int f[11111];
int g[11111];
int d[11111];
int n;

int main()
{
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[n-i+1]=a[i];
        }
        for (int i=1;i<=n;i++) d[i]=OO;
        for (int i=1;i<=n;i++)
        {
            int k=lower_bound(d+1,d+n+1,a[i])-d;
            f[i]=k;
            d[k]=a[i];
        }
        for (int i=1;i<=n;i++) d[i]=OO;
        for (int i=1;i<=n;i++)
        {
            int k=lower_bound(d+1,d+n+1,b[i])-d;
            g[n-i+1]=k;
            d[k]=b[i];
        }
        //for (int i=1;i<=n;i++) cerr<<f[i]<<" ";cerr<<endl;
        //for (int i=1;i<=n;i++) cerr<<g[i]<<" ";cerr<<endl;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int tmp=min( f[i], g[i] );
            tmp=(tmp-1)*2+1;
            if (tmp>ans) ans=tmp;
        }
        printf("%d\n",ans);
    }
    return 0;
}
