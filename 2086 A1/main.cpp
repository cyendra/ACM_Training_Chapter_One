#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double a[3001];
double c[3001];
double dps(int i);

double dps(int i)
{
    if (a[i]!=0)
    {
        return a[i];
    }
    return ( (dps(i-1)+dps(i+1))/2 -c[i] );
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        scanf("%lf%lf",&a[0],&a[n+1]);
        for (int loop=1;loop<=n;loop++)
        {
            scanf("%lf",&c[loop]);
        }
        printf("%0.2f\n",dps(1));

    }
    return 0;
}
