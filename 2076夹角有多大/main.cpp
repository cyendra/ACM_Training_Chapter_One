#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int n,h,m,s;
    double p1,p2,t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&h,&m,&s);
        if (h>=12) h-=12;
        p1=h*30.0+m*0.5+s/120.0;
        p2=m*6.0+s*0.1;
        if (p2>p1)
        {
            t=p1;
            p1=p2;
            p2=t;
        }
        if (p1-p2<p2+360-p1)
        {
            printf("%d\n",(int)(p1-p2));
        }
        else
        {
            printf("%d\n",(int)(p2+360-p1));
        }
    }
    return 0;
}
