#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    __int64 f[36][36];
    int n,t;
    t=0;
    memset(f,0,sizeof(f));
    for (int i=0;i<=35;i++)
    {
        f[0][i]=1;
        f[i][0]=1;
    }
    while (scanf("%d",&n))
    {
        if (n==-1)
        {
            break;
        }
        t++;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                if (f[i][j]!=0) continue;
                if (i==j)
                {
                    f[i][j]=f[i][j-1];
                    continue;
                }
                f[i][j]=f[i-1][j]+f[i][j-1];
            }
        }
        printf("%d %d %I64d\n",t,n,f[n][n]*2);
    }
    return 0;
}
