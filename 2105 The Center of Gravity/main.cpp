#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    double x1,x2,x3,y1,y2,y3,x,y;
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        for (int loop=0;loop<n;loop++)
        {
            scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
            x=x1+x2+x3;
            x=x/3;
            y=y1+y2+y3;
            y=y/3;
            printf("%0.1f %0.1f\n",x,y);
        }
    }
    return 0;
}
