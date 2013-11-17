#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=411111;
typedef long long LL;
LL a[maxn],b[maxn],c[maxn];
int n;

int main()
{
    while (~scanf("%d",&n)){
        if (n==0) break;
        for (int i=0;i<n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            a[i]=x-y;
            b[i]=y-z;
            c[i]=z-x;
        }
        sort(a,a+n);
        sort(b,b+n);
        sort(c,c+n);
        LL ans=0;
        for (int i=0;i<n;i++){
            ans+=(a[i]+b[i]+c[i])*(2*i-n+1);
        }
        printf("%I64d\n",ans/2);
    }
    return 0;
}
