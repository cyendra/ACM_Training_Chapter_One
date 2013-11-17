#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int maxn=110000;
int n;
LL a[maxn];
LL k;

bool C(int x){
    LL m=0;
    for (int i=1;i<=n&&m<=x;i++){
        if (a[i]-x>0){
            m+=(a[i]-x)/(k-1)+((a[i]-x)%(k-1)>0?1:0);
        }
    }
    //cerr<<"x="<<x<<" m="<<m<<endl;
    return m<=x;
}

int main()
{
    while (~scanf("%d",&n)){
        LL l=1,r=0;
        LL ans=0;
        for (int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            r=max(r,a[i]);
        }
        scanf("%I64d",&k);
        if (k==1) ans=r;
        else{
            while (l<=r){
                LL mid=l+(r-l)/2;
                if (C(mid)){
                    ans=mid;
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

