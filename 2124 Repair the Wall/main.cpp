#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[600];
int cmp(int a,int b);
int cmp(int a,int b)
{
    if (a>b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int l,n,ans;
    int sum;
    while (scanf("%d%d",&l,&n)!=EOF)
    {
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if (l==0)
        {
            printf("0\n");
            continue;
        }
        if (sum<l)
        {
            printf("impossible\n");
            continue;
        }
        if (sum==l)
        {
            printf("%d\n",n);
            continue;
        }
        sort(a,a+n,cmp);
        for (int i=0;i<n;i++)
        {
            l=l-a[i];
            if (l<=0)
            {
                ans=i+1;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
