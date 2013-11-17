#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    __int64 f[51]={0};
    f[0]=0;
    f[1]=1;
    f[2]=1;
    for (int i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while (scanf("%d",&n))
    {
        if (n==-1)
        {
            break;
        }
        printf("%I64d\n",f[n]);
    }
    return 0;
}
