#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int a[101]={0},f[101][101];
    int n,k,t,tmp;
    while (scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (k=1;k<=n;k++)
        {
            //前半部分
            for (int i=1;i<=k;i++)
            {
                f[i][k]=1;
                for (int j=1;j<i;j++)
                {
                    if (a[i]>a[j])
                    {
                        if ( f[j][k]+1 > f[i][k] )
                        {
                            f[i][k]=f[j][k]+1;
                        }
                    }
                }
            }
            //后半部分
            tmp=0;
            t=k+1;
            while ((t<=n)and(a[t]>=a[k]))
            {
                t++;
                tmp++;
            }
            f[t][k]=f[k][k]+tmp;
            for (int i=t;i<=n;i++)
            {
                for (int j=t;j<i;j++)
                {
                    if (a[i]<a[j])
                    {
                        if ( f[j][k]+1>f[i][k] )
                        {
                            f[i][k]=f[j][k]+1;
                        }
                    }
                }
            }
        }
        tmp=0;
        for (k=1;k<=n;k++)
        {
            for (int i=k;i<=n;i++)
            {
                if (f[i][k]>tmp)
                {
                    tmp=f[i][k];
                }
            }
        }
        printf("%d\n",n-tmp);
    }
    return 0;
}
