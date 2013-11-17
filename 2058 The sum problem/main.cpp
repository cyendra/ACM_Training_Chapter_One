#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int m,n,t;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if ((m==0)&&(n==0))
        {
            break;
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<n;j++)
            {
                t=i*j+j*(j-1)/2;
                if ((t==m) && (i>=1) && ((i+j)<=n))
                {
                    printf("[%d,%d]\n",i,i+j-1);
                }

            }
        }
    }
    return 0;
}
