#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double x1,x2,y1,y2;
    double ans;
    while (scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%0.2f\n",ans);
    }
    return 0;
}
