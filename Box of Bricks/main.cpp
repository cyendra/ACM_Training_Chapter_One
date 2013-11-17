#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a[51];
    int n,sum,avg,ans;
    bool one=true;
    int loop=0;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0)
        {
            break;
        }
        loop++;
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
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
        printf("Set #%d\n",loop);
        printf("The minimum number of moves is %d.\n\n",ans);
    }
    return 0;
}
