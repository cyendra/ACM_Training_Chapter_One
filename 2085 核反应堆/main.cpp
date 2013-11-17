#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    __int64 f[34][2];
    for (int i=0;i<34;i++)
    {
        for (int j=0;j<2;j++)
        {
            f[i][j]=0;
        }
    }
    f[0][0]=1;
    for (int i=1;i<34;i++)
    {
        f[i][0]=f[i-1][0]*3+f[i-1][1]*2;
        f[i][1]=f[i-1][0]*1+f[i-1][1]*1;
    }
    while (scanf("%d",&n))
    {
        if (n==-1) break;
        printf("%I64d, %I64d\n",f[n][0],f[n][1]);
    }
    return 0;
}
