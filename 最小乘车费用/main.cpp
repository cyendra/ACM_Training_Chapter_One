#include <cstdio>
#include <iostream>
#include <cstring>
#define Max 32767
int a[1001][1001];
int main()
{
    int x, y, time;
    int t, s, d,n,min,k,minf,minj;
    int f[1001];
    bool v[1001],ok;

    while (scanf("%d%d%d", &t, &s, &d) != EOF)
    {
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
                a[i][j] = Max;
        }

        n = 0;

        for (int i = 0; i < t; i++)
        {
            scanf("%d%d%d", &x, &y, &time);
            if (a[x][y] > time) a[x][y] = a[y][x] = time;
            if ( n < x) n = x;
            if ( n < y) n = y;
        }



        for (int i = 0; i < s; i++)
        {
            scanf("%d", &x);
            a[0][x] = a[x][0] = 0;
        }

        for (int i = 0; i <= n; i++)
            v[i]=false;

        ok=false;
        v[0]=true;

        for (int i=0;i<=n;i++)
        {
            f[i]=Max;
        }

        f[0]=0;

        for (int p=0;p<=n;p++)
        {
            minf=Max;
            for (int i=0;i<=n;i++)
            {
                if (v[i]==true)
                {
                    //printf("i=%d\n",i);
                    for (int j=0;j<=n;j++)
                    {
                        if ((v[j]==false)and(f[j]>f[i]+a[i][j]))
                        {
                            //printf("j=%d v[%d]=%d\n",j,v[j]);
                            f[j]=f[i]+a[i][j];
                            if (f[j]<minf)
                            {
                                //printf("f[%d]=%d",minj,f[minj]);getchar();
                                minf=f[j];
                                minj=j;
                            }
                        }
                    }
                }

                //printf("f[%d]=%d",minj,f[minj]);getchar();
            }
            v[minj]=true;
        }
        min=Max;
        for (int i=1;i<=d;i++)
        {
            scanf("%d",&x);
            if (f[x]<min)
            {
                min=f[x];
            }
        }
        printf("%d\n",min);


    }
    return 0;
}
