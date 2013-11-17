#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    __int64 a[23],m;
    int n;
    a[0]=0;
    a[1]=1;
    for (int i=2;i<=20;i++)
    {
        a[i]=i*a[i-1];
    }
    while (scanf("%d%I64d",&n,&m))
    {
        printf("%I64d\n",a[n]-m);
    }
    return 0;
}
