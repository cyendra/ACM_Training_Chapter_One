#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int c,n;
    int a[100][100];
    int f[100][100];
    scanf("%d",&c);
    for (int loop=1;loop<=c;loop++)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for (int i=0;i<n;i++)
        {
            f[n-1][i]=a[n-1][i];
        }
        for (int i=n-2;i>=0;i--)
        {
            for (int j=0;j<=i;j++)
            {
                f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
            }
        }
        printf("%d\n",f[0][0]);
    }
    return 0;
}
