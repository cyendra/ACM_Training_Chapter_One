#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[1111][2222][2];

const int mod=100000007;

int main()
{
    int T,n,k;
    memset(f,0,sizeof(f));
    f[1][1][0]=1;
    f[1][2][1]=1;
    for (int i=0; i<=1000; i++)
    {
        for (int j=0; j<=i*2; j++)
        {
            f[i+1][j][0]=(f[i+1][j][0]+f[i][j][0]+f[i][j][1]*2)%mod;
            f[i+1][j+1][0]=(f[i+1][j+1][0]+f[i][j][0]+f[i][j][1])%mod;
            f[i+1][j][1]=(f[i+1][j][1]+f[i][j][1])%mod;
            f[i+1][j+1][1]=(f[i+1][j+1][1]+f[i][j][0]*2+f[i][j][1]*2)%mod;
            f[i+1][j+2][1]=(f[i+1][j+2][1]+f[i][j][0]+f[i][j][1])%mod;
        }
    }
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",(f[n][k][0]+f[n][k][1])%mod);
    }
    return 0;
}
