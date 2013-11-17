#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int m,n,t,p;
    int a[50];
    while (scanf("%d%d",&m,&n))
    {
        p=0;
        for (int i=m;i<=n;i++)
        {
            int x=i;
            //t=(x/100)*(x/100)*(x/100); //+(i/10)*(i/10)*(i/10)+(i/1)*(i/1)*(i/1);
            t=(x % 10)*(x % 10)*(x % 10);
            x=x/10;
            t=t+(x % 10)*(x % 10)*(x % 10);
            x=x/10;
            t=t+(x % 10)*(x % 10)*(x % 10);
            if (t==i)
            {
                a[p]=i;
                p++;
            }
        }
        for (int i=0;i<p;i++)
        {
            printf("%d ",a[i]);
        }
        if (p==0)
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
