#include <iostream>
#include <cstdio>

using namespace std;

typedef struct{
    double x;
    double y;
}POINT;

int main()
{
    int t;
    POINT p1,p2,p3,pt;
    double a1,b1,c1,a2,b2,m,n,ans;
    scanf("%d",&t);
    int loop;
    for (loop=0;loop<t;loop++)
    {
        scanf("%lf%lf",&p1.x,&p1.y);
        scanf("%lf%lf",&p2.x,&p2.y);
        scanf("%lf%lf",&p3.x,&p3.y);
        //计算抛物线方程
        m=p1.x;
        n=p1.y;
        a1=(p2.y-n)/((p2.x-m)*(p2.x-m));
        b1=-2*m*a1;
        c1=a1*m*m+n;
        //检验
        //printf("%0.2f %0.2f %0.2f\n",a1,b1,c1);
        //计算直线方程
        if (p3.x<p2.x)
        {
            pt=p2;
            p2=p3;
            p3=pt;
        }
        a2=(p3.y-p2.y)/(p3.x-p2.x);
        b2=p3.y-a2*p3.x;
        //检验
        //printf("%0.2f %0.2f\n",a2,b2);
        ans=(a1/3)*(p3.x )*(p3.x)*(p3.x)+(b1/2)*(p3.x)*(p3.x)+c1*p3.x;
        ans=ans-((a2/2)*(p3.x)*(p3.x)+b2*(p3.x));
        ans=ans-(a1/3)*(p2.x )*(p2.x)*(p2.x)+(b1/2)*(p2.x)*(p2.x)+c1*p2.x;
        ans=ans+((a2/2)*(p2.x)*(p2.x)+b2*(p2.x));
        printf("%0.2f\n",ans);
    }
    return 0;
}
