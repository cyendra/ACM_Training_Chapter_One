#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    unsigned long long int sq[65];
    __int64 a,b,max,min;
    int k;
    sq[0]=1;
    sq[1]=2;
    for (int i=1;i<=63;i++)
    {
        sq[i]=sq[i-1]*2;
    }
    while (scanf("%d",&k)!=EOF)
    {
        scanf("%I64d%I64d",&a,&b);
        max=sq[k-1]-1;
        min=-sq[k-1];
        if ( (a==0) || (b==0) )
        {
            printf("WaHaHa\n");
            continue;
        }
        if ( ( (a>0)&&(b<0) )||( (a<0)&&(b>0) ) )
        {
            printf("WaHaHa\n");
            continue;
        }
        if (a>0)
        {
            if (max-a<b)
            {
                printf("Yes\n");
            }
            else
            {
                printf("WaHaHa\n");
            }
            continue;
        }
        if (a<0)
        {
            if (min-a>b)
            {
                printf("Yes\n");
            }
            else
            {
                printf("WaHaHa\n");
            }
            continue;
        }
    }
    return 0;
}
