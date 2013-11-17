#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,m;
    double max,t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        max=0.0;
        scanf("%d",&m);
        for (int j=1;j<=m;j++)
        {
            scanf("%lf",&t);
            if (t>max)
            {
                max=t;
            }
        }
        printf("%0.2f\n",max);
    }
    return 0;
}
