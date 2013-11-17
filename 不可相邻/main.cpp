#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    __int64 f[101][2];
    int n;
    memset(f,0,sizeof(f));
    f[1][0]=1;
    f[1][1]=1;
    while (scanf("%d",&n))
    {
        for (int i=2;i<=n;i++)
        {
            f[i][1]=f[i-1][0];
            f[i][0]=f[i-1][1]+f[i-1][0];
        }
        printf("%I64d\n",f[n][0]+f[n][1]);
    }
    return 0;
}
