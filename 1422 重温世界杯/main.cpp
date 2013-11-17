#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n;
int a[401000];
int f[401000];
int ans,t;
int main()
{
    int w,l;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            //cin >> w >> l;
            scanf("%d%d",&w,&l);
            a[i]=w-l;
            a[i+n]=w-l;
        }
        memset(f,0,sizeof(f));
        ans=0;
        t=0;
        for (int i=1;i<(n<<1);i++)
        {
            if (ans>=n) break;
            if ( f[i-1]<0 )
            {
                f[i]=a[i];
                t=0;
                if (f[i]>=0) t++;
                continue;
            }
            f[i]=f[i-1]+a[i];
            if (f[i]>=0) t++;
            if (t>ans)
            {
                ans=t;
            }
        }
        if (ans>=n)
        {
            //cout << n << endl;
            printf("%d\n",n);
        }
        else
        {
            //cout << ans << endl;
            printf("%d\n",ans);
        }
    }
    return 0;
}
