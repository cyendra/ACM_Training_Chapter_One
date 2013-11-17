#include <iostream>
#include <cstdio>
using namespace std;

int a[100010];

int main()
{
    int n,m;
    int l,r,d,ans,t;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&t);
            l=0;
            r=n-1;
            ans=-1;
            while (l<=r)
            {
                d=(l+r)/2;
                if (a[d]==t)
                {
                    ans=d;
                    break;
                }
                if (a[d]<t)
                {
                    l=d+1;
                }
                else if (a[d]>t)
                {
                    r=d-1;
                }
            }
            if (ans==-1)
            {
                printf("Not find!\n");
            }
            else
            {
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
