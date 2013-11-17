#include <iostream>
#include <cstdio>
#include <math.h>
#define PI 3.1415927
using namespace std;

int main()
{
    double r,ans;
    while (scanf("%lf",&r)!=EOF)
    {
        ans=4.0*PI*pow(r,3)/3.0;
        printf("%0.3f\n",ans);
    }
    return 0;
}
