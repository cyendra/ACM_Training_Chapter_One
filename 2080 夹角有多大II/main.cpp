#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    int t;
    double x1,y1,x2,y2,OA,OB,s,sin,ans;
    scanf("%d",&t);
    for (int loop=1;loop<=t;loop++)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        OA=sqrt(x1*x1+y1*y1);
        OB=sqrt(x2*x2+y2*y2);
        s=fabs(x1*y2-x2*y1)/2;
        sin=2*s/(OA*OB);
        ans=asin(sin)/acos(-1)*180;
        if (ans!=0)
        {
            if ( (x1*x2<=0) && (y1*y2<=0) )
            {
                ans=180-ans;
            }
        }
        else
        {
            if (x1*x2<0)
            {
                ans=180;
            }
            else
            {
                ans=0;
            }
        }
        printf("%0.2f\n",ans);
    }
    return 0;
}
