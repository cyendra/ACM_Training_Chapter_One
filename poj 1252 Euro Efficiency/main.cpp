#include <iostream>
#include <cstdio>
#define OO 9999999
using namespace std;

int a[10];
int f[111111];
int n,m;
int T;
int sum,ans;
bool flag;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        n=0;
        for (int i=0;i<6;i++)
        {
            scanf("%d",&a[i]);
            n=max(n,a[i]);
        }
        m=(100-n+1)*n;
        m=max(m,100);
        for (int i=0;i<=m;i++)
        {
            f[i]=OO;
        }
        f[0]=0;
        sum=0;
        ans=0;
        flag=true;
        while (flag)
        {
            flag=false;
            for (int k=0;k<6;k++)
            {
                for (int i=a[k];i<=m;i++)
                {
                    if ( f[i]>f[i-a[k]]+1 )
                    {
                        f[i]=f[i-a[k]]+1;
                        flag=true;
                    }
                }
            }
            for (int k=0;k<6;k++)
            {
                for (int i=m-a[k];i>=0;i--)
                {
                    if ( f[i]>f[i+a[k]]+1 )
                    {
                        f[i]=f[i+a[k]]+1;
                        flag=true;
                    }
                }
            }
        }
        for (int i=1;i<=100;i++)
        {
            sum+=f[i];
            ans=max( ans , f[i] );
        }
        printf("%0.2f %d\n",sum/100.0,ans);
    }
    return 0;
}
