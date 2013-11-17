#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=111111;
double a[maxn];

int main()
{
    int n;
    double sum,avg,ans1,ans2;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%lf",&a[i]);
            sum+=a[i];
        }
        avg=sum/n;
        ans1=0;
        ans2=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]<avg) ans1+=double(int((avg-a[i])*100))/100.0;
            if (avg<a[i]) ans2+=double(int((a[i]-avg)*100))/100.0;
        }
        printf("$%0.2f\n",max(ans1,ans2));
    }
    return 0;
}
