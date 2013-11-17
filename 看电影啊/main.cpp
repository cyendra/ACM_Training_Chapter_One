/*
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int ts[100],te[100],lo[100];
    int f[100000]={0};
    int n,max,d;
    while (scanf("%d",&n))
    {
        if (n==-1)
        {
            break;
        }
        max=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&ts[i],&te[i]);
            lo[i]=te[i]-ts[i];
            if (te[i]>max)
            {
                max=te[i];
            }
        }
        for (int i=0;i<max;i++)
        {
            d=0;
            if(i!=0){f[i]=f[i-1]; }
            for (int j=0;j<=n;j++)
            {
                if ( (te[j]==i) and ( (i-lo[j])>=0 ) and ( ( f[i-lo[j]]+1 ) > d ) )
                {
                    d=f[i-lo[j]]+1;
                }
            }
            if (d>f[i])
            {
                f[i]=d;
            }
        }
        while (f[max]==0){max--;}
        printf("%d\n",f[max]);
    }
    return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int x, y;
}node;
node num[102];
int cmp(const void *a, const void *b)
{
    return (*(node *)a).y-(*(node *)b).y;
}
int main()
{
    int i = 0, j = 0, n = 0, s = 0, e = 0, min = 0, k = 0, sum = 0;
    while(scanf("%d",&n), n+1)
    {
        for(i = 0; i<n; i++)
            scanf("%d %d",&num[i].x, &num[i].y);
        qsort(num, n, sizeof(num[0]), cmp);
        e = 0;
        sum = 0;
        for(i = 0; i<n; i++)
        {
            if(num[i].x>=e)//这个节目的开始时间大于等于上一个节目的结束时间
            {
                e = num[i].y;
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
