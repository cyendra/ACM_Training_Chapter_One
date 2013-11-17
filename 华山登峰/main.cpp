#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    __int64 a[101]={0};
    int n;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    a[3]=1;
    while (scanf("%d",&n))
    {
        if (a[n]!=0)
        {
            printf("%I64d",a[n]);
            continue;
        }
        for (int i=4;i<=n;i++)
        {
            a[i]=a[i-1]+a[i-3];
        }
        printf("%I64d\n",a[n]);
    }
    return 0;
}
