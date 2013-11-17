#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,ans;
    int a[4]={0};
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)break;
        a[0]=1;
        a[1]=0;
        a[2]=0;
        a[3]=0;
        for (int i=1;i<n;i++)
        {
            a[0]=a[0]+a[3];
            a[3]=a[2];
            a[2]=a[1];
            a[1]=a[0];
        }
        ans=a[0]+a[1]+a[2]+a[3];
        printf("%d\n",ans);
    }
    return 0;
}
