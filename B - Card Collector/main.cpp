#include<cstdio>
int main()
{
    int i,n;
    double t,min;
    while(~scanf("%d",&n))
    {
        min=2;
        for(i=0; i<n; ++i)
        {
            scanf("%lf",&t);
            if(t<min)min=t;
        }
        if(n==1)printf("%.3f\n",1/min);
        else printf("%.3f\n",((1/min*(n-1))+(1/min)/n));
    }
}


/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;
    double p[22];
    double ans,sum;
    while (~scanf("%d",&n))
    {
        ans=0;
        for (int i=1;i<=n;i++) scanf("%lf",&p[i]);
        if (n==1) ans=1.0/p[1];
        else
        {
            ans=0;
            sum=0;
            for (int i=1;i<=n;i++)
            {
                ans+=1.0/p[i];
                sum+=p[i];
            }
            ans-=1.0/sum;
        }
        printf("%0.3f\n",ans);
    }
    return 0;
}
*/
