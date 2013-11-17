#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,ans;
    int a[20];
    while (scanf("%d",&n)!=EOF)
    {
        ans=1;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]%2!=0)
            {
                ans=ans*a[i];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
