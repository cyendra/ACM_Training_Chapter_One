#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int f[50][2]={0};
    int n;
    f[1][0]=2;
    f[1][1]=1;
    while (scanf("%d",&n))
    {
        for (int i=2;i<=n;i++)
        {
            f[i][0]=(f[i-1][0]+f[i-1][1])*2;
            f[i][1]=f[1][0];
        }
        printf("%d\n",(f[n][0]+f[n][1]));
    }
    return 0;
}
