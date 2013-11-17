#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=55555;

int a[maxn];
int L,n,m;

bool C(int x){
    int k=0;
    int p=0;
    for (int i=1;i<=n;i++){
        if (a[i]-a[p]<x) k++;
        else{
            p=i;
        }
    }
    if (a[n+1]-a[p]<x) k++;
    if (k>m) return false;
    return true;
}

int main()
{
    while (~scanf("%d%d%d",&L,&n,&m)){
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        a[0]=0;
        a[n+1]=L;
        int l=0,r=L;
        int ans=0;
        while (l<=r){
            int mid=l+(r-l)/2;
            if (C(mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
