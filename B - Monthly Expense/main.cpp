#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn=111000;
int n,m;
int a[maxn];
bool C(int x){
    int sum=0;
    int cnt=1;
    for (int i=1;i<=n;i++){
        if (sum+a[i]>x){
            sum=0;
            cnt++;
        }
        sum+=a[i];
    }
    return cnt<=m;
}
int main()
{
    while (~scanf("%d%d",&n,&m)){
        int l=0,r=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            l=max(l,a[i]);
            r+=a[i];
        }
        int ans=0;
        while (l<=r){
            int mid=l+(r-l)/2;
            if (C(mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
