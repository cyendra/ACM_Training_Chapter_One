#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int p[21],f[21];
    int t,n;
    double ans;
    p[0]=1;
    p[1]=1;
    for (int i=2;i<=20;i++)
    {
        p[i]=p[i-1]*i;
    }
    f[0]=0;
    f[1]=0;
    f[2]=1;
    for (int i=3;i<=20;i++)
    {
        f[i]=(f[i-1]+f[i-2])*(i-1);
    }
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d",&n);
        ans=( (double)f[n] )/( (double)p[n] )*100;
        printf("%0.2f%%\n",ans);
    }
    return 0;
}
