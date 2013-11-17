#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int c1[121],c2[121];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<=n;i++)
        {
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                for (int k=0;k+j<=n;k+=i)
                {
                    c2[k+j]+=c1[j];
                }
            }
            for (int j=0;j<=n;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
