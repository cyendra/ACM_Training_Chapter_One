#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int mina(int a,int b)
{
    if (a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}


int main()
{
    int a[100][100];
    int f[100][100];
    int n,k;
    while (scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        //getchar();
        for (int i=1;i<=n;i++)
        {
            f[n][i]=a[n][i];
        }
        for (int i=n;i>=2;i--)
        {
            for (int j=1;j<i;j++)
            {
                f[i-1][j]=mina(f[i][j],f[i][j+1])+a[i-1][j];
                //printf("f[%d][%d]=%d",i-1,j,f[i-1][j]);getchar();
            }
        }
        printf("%d\n",f[1][1]);
    }
    return 0;
}
