#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,e;
    double ans,tmp;
    while ( scanf("%d",&n)!=EOF )
    {
        if (n==0)
        {
            break;
        }
        ans=(double)(1.0*n*(n+1)*(n+2)/6.0);
        e=(int)log10(ans);
        tmp=ans/pow(10.0,(1.0*e));
        printf("%0.2lfE%d\n",tmp,e);

    }
    return 0;
}
