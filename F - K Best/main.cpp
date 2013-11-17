#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=111111;
const double eps=1e-8;
int n,k;
struct Data{
    int v,w;
    double c;
    int idx;
}a[maxn];
bool cmp(Data a,Data b){
    //if (fabs(a.c-b.c)<eps) return a.idx<b.idx;
    return a.c>b.c;
}
bool C(double x){
    for (int i=1;i<=n;i++){
        a[i].c=a[i].v-x*a[i].w;
    }
    //sort(a+1,a+n+1,cmp);
    partial_sort(a+1,a+1+k,a+1+n,cmp);
    double sum=0;
    for (int i=1;i<=k;i++){
        sum+=a[i].c;
    }
    return sum>=0;
}

int main()
{
    while (~scanf("%d%d",&n,&k)){
        int sum=0;
        for (int i=1;i<=n;i++){
            scanf("%d%d",&a[i].v,&a[i].w);
            a[i].idx=i;
            sum+=a[i].v;
        }
        double l=0.0,r=1.0*sum;
        while (fabs(r-l)>eps){
            double mid=(l+r)/2;
            if (C(mid)) l=mid;
            else r=mid;
        }
        for (int i=1;i<=k-1;i++){
            printf("%d ",a[i].idx);
        }
        printf("%d\n",a[k].idx);
    }
    return 0;
}
