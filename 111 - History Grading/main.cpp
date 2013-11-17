#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=1111;
int a[maxn];
int c[maxn];
int f[maxn];
int ans;
int n;

int main()
{
    int t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        c[i]=t;
    }
    while (~scanf("%d",&t))
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        a[t]=c[1];
        for (int i=2;i<=n;i++)
        {
            scanf("%d",&t);
            a[t]=c[i];
        }
        ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int k=0;k<i;k++)
            {
                if (a[i]>a[k]) f[i]=max( f[i], f[k]+1 );
            }
            ans=max(ans,f[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
