#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int l,d,v,g,r,t;
    double ans;
    scanf("%d%d%d%d%d",&l,&d,&v,&g,&r);
    t=(d/v)%(g+r);
    if (t<g)
    {
        ans=(double)l/v;
    }
    else
    {
        ans=d/v+(g+r-t)+(double)(l-d)/v;
    }
    printf("%0.8f\n",ans);
    return 0;
}
