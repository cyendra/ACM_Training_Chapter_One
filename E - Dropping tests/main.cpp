#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const double eps=1e-6;
const int maxn=1111;
double a[maxn];
double b[maxn];
double c[maxn];
int n,k;

int main()
{
    while (~scanf("%d%d",&n,&k)){
        if (n==0&&k==0) break;
        for (int i=1;i<=n;i++) scanf("%lf",&a[i]);
        for (int i=1;i<=n;i++) scanf("%lf",&b[i]);
        double l=0.0,r=1.0;
        double mid;
        while (r-l>eps){
            mid=(l+r)/2.0;
            for (int i=1;i<=n;i++){
                c[i]=a[i]-b[i]*mid;
            }
            sort(c+1,c+n+1);
            double sum=0;
            for (int i=k+1;i<=n;i++){
                sum+=c[i];
            }
            if (sum>0) l=mid;
            else r=mid;
        }
        printf("%0.0f\n",mid*100);
    }
    return 0;
}
