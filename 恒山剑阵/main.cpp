#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    __int64 f[61][61];
    int a1,a2,a3,m,n;
    while (scanf("%d%d%d%d%d",&a1,&a2,&a3,&m,&n))
    {
        memset(f,0,sizeof(f));
        f[1][1]=(__int64)a1;
        f[2][1]=(__int64)a2;
        f[2][2]=(__int64)a3;
        for (int i=3;i<=m;i++)
        {
            for (int j=1;j<=i;j++)
            {
                f[i][j]=f[i-1][j]+f[i-1][j-1];
            }
        }
        printf("%I64d\n",f[m][n]);
    }
    return 0;
}
