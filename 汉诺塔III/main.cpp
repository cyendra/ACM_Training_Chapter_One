#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

__int64 f[40]={0};
__int64 han(int n)
{
    if (f[n]!=0)
    {
        return f[n];
    }
    else if(n==1)
    {
        f[n]=2;
        return f[n];
    }
    else
    {
        f[n]=han(n-1)*3+2;
        return f[n];
    }
}

int main()
{
    int n;
    __int64 ans;
    while (scanf("%d",&n)!=EOF)
    {

        ans=han(n);
        //printf("%.0f ", pow(3, n) - 1);
        printf("%I64d\n",ans);
    }

    return 0;
}
