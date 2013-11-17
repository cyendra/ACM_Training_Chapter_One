
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
//定义结构
typedef struct
{
    int x, y;
}node;
node num[102];
//快排用函数
int cmp(const void *a, const void *b)
{
    if ((*(node *)a).y!=(*(node *)b).y)
    {
        return (*(node *)a).y-(*(node *)b).y;
    }
    else
    {
        return (*(node *)b).x-(*(node *)a).x;
    }

}
//main
int main()
{
    int f[101];
    int n = 0, max = 0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        for(int i = 0; i<n; i++)
            scanf("%d %d",&num[i].x, &num[i].y);
        qsort(num, n, sizeof(num[0]), cmp);
        //-----------------------------------------------------------

        for (int i=n;i>=1;i--)
        {
            f[i]=num[i].y-num[i].x;
            for (int k=i+1;k<=n;k++)
            {
                if (num[i].y<=num[k].x)
                {
                    if ( (f[k]+num[i].y-num[i].x) > f[i] )
                    {
                        f[i]=f[k]+num[i].y-num[i].x;
                    }
                }
            }
        }
        max=f[1];
        for (int i=1;i<n;i++)
        {
            if (f[i]>max)
            {
                max=f[i];
            }
        }
        printf("%d",max);
        //-----------------------------------------------------------
    }
    return 0;
}
