#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=11111;

int a[maxn];
int f[maxn];
int key,p,ans;
bool ok;
int main()
{
    int T,cas,n;
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d",&cas,&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            f[i]=f[i-1]+a[i];
        }
        for (int i=1;i<=n;i++)
        {
            p=i;
            ok=true;
            key=0;
            while (p<n)
            {
                key+=f[i];
                int k=lower_bound(f+1,f+n+1,key)-f;
                if (f[k]!=key)
                {
                    ok=false;
                    break;
                }
                p=k;
            }
            if (ok)
            {
                ans=f[i];
                break;
            }
        }
        printf("%d %d\n",cas,ans);
    }
    return 0;
}
