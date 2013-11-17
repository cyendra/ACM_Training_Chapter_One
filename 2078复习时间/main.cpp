#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    if (a<b)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int t,n,m;
    int a[41],f[41];
    scanf("%d",&t);
    for (int loop=1;loop<=t;loop++)
    {
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        for (int i=0;i<n;i++)
        {
            //printf("%d ",a[i]);
            f[i]=(100-a[i])*(100-a[i]);
        }
        for (int j=1;j<m;j++)
        {
            for (int i=0;j<n;i++)
            {
                for (int k=1;k<=i;k++)
                {
                    if (f[i-k]+(a[i-k]-a[i])*(a[i-k]-a[i])>f[i])
                    {
                        f[i]=f[i-k]+(a[i-k]-a[i])*(a[i-k]-a[i]);
                    }
                }
            }
        }
        int max=0;
        for (int i=0;i<n;i++)
        {
            if (f[i][m-1]>max)
            {
                max=f[i][m-1];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
