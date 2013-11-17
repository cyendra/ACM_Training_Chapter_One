#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,ans,los;
    int a[101],b[101];
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        ans=0;
        los=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]>b[i])
            {
                ans+=2;
            }
            if (a[i]==b[i])
            {
                ans++;
                los++;
            }
            if (a[i]<b[i])
            {
                los+=2;
            }
        }
        printf("%d vs %d\n",ans,los);
    }
    return 0;
}
