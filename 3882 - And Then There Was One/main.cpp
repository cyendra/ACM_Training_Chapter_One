#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[11111];

int main()
{
    int n,k,m;
    while (~scanf("%d%d%d",&n,&k,&m))
    {
        if (n==0) break;
        f[1]=0;
        for (int i=2;i<=n;i++) f[i]=(f[i-1]+k)%i;
        int ans=(f[n]+m-k+1)%n;
        if (ans<=0) ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}
