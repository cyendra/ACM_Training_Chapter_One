#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[51];
    int n,sum,avg,ans;
    bool one=true;
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }

        if (one==true)
        {
            one=false;
        }
        else
        {
            printf("\n");
        }

        avg=sum/n;
        ans=0;
        for (int i=0;i<n;i++)
        {
            if (a[i]>avg)
            {
                ans+=a[i]-avg;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
