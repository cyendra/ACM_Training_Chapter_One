
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,sum;
    int p[101],m[101];
    int f[100000];
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        sum=0;
        memset(p,0,sizeof(p));
        memset(m,0,sizeof(m));
        memset(f,0,sizeof(f));
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i],&m[i]);
            sum+=p[i]*m[i];
        }
        if (sum%3!=0)
        {
            printf("sorry\n");
            continue;
        }
        sum=sum/3;
        f[0]=1;
        for (int j=0;j<n;j++)
        {
            for (int i=sum;i>=0;i--)
            {
                for (int k=1;(k<=m[j]) && (i+p[j]*k<=sum) ;k++)
                {
                        f[i+p[j]*k]=(f[i+p[j]*k]+f[i])%10000;
                }
            }
        }
        if (f[sum]==0)
        {
            printf("sorry\n");
            continue;
        }
        printf("%d\n",f[sum]);
    }
    return 0;
}

/*
#include <stdio.h>
#include <string.h>
int a[10000];
int p[100];
int m[100];
int main ()
{
int n,sum,i,j,k;
while (scanf("%d",&n)!=EOF)
{
   if (n==0) return 0;
   sum=0;
   for (i=0;i<n;i++)
   {
    scanf("%d %d",&p[i],&m[i]);
    sum+=p[i]*m[i];
   }
   if (sum%3)     //不能三等分的，一定不行
   {
    printf ("sorry\n");
    continue;
   }
   sum/=3;
   memset(a,0,sizeof(a));
   a[0]=1;
   for (i=0;i<n;i++)
   {
    for (j=sum;j>=0;j--)
    {
     for (k=1;k<=m[i]&& j+k*p[i]<=sum;k++)
      a[j+k*p[i]]=(a[j+k*p[i]]+a[j])%10000;
    }
   }
   if (a[sum])    //如果分法数量为0 证明不可分
    printf ("%d\n",a[sum]);
   else printf ("sorry\n");
}
return 0;
}
*/
