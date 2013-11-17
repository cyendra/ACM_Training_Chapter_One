#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N,p,q;
const int OO=1e9;

int a1[111111];
int a2[111111];
int c[111111];
int a[111111];
int g[111111];
int d[111111];

int main()
{
    int T,n;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&N,&p,&q);
        memset(c,0,sizeof(c));
        memset(g,0,sizeof(g));
        n=0;
        for (int i=1;i<=p+1;i++)
        {
            scanf("%d",&a1[i]);
            c[a1[i]]=i;
        }
        for (int i=1;i<=q+1;i++)
        {
            scanf("%d",&a2[i]);
            if (c[a2[i]]) a[n++]=c[a2[i]];
        }
        //LIS
        for (int i=0;i<=n;i++) g[i]=OO;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            int k=lower_bound(g+1,g+n+1,a[i])-g;
            d[i]=k;
            g[k]=a[i];
            ans=max(ans,d[i]);
        }
        printf("Case %d: %d\n",cas,ans);
    }

    return 0;
}
