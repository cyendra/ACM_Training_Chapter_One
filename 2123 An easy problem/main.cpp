#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,c;
    int a[10][10];
    for (int i=0;i<=9;i++)
    {
        for (int j=0;j<=9;j++)
        {
            a[i][j]=i*j;
        }
    }
    for (int i=1;i<=9;i++)
    {
        a[1][i]=i;
        a[i][1]=i;
    }
    scanf("%d",&c);
    for (int loop=1;loop<=c;loop++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("%d\n",a[i][n]);
        }
    }
    return 0;
}
