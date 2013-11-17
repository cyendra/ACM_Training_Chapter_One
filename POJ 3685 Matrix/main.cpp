#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LL;
const LL INFF=1LL<<50;
int n;
LL m;
LL f(LL i,LL j){
    return i*i+100000*i+j*j-100000*j+i*j;
}
bool can(LL x){
    int i;
    LL sum,l,r,res,mid;
    sum=0;
    for (i=1;i<=n;i++){
        l=1,r=n;
        res=n+1;
        while (l<=r){
            mid=(l+r)>>1;
            if (f(mid,i)>=x){
                res=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        sum+=res-1;
    }
    return sum>=m;
}

int main()
{
    int T;
    LL l,r,ans,mid;
    scanf("%d",&T);
    while (T--){
        scanf("%d%I64d",&n,&m);
        l=-INFF,r=INFF;
        ans=0;
        while (l<=r){
            mid=(l+r)>>1;
            if (can(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%I64d\n",ans-1);
    }
    return 0;
}
