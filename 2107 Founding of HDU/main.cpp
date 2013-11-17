#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    int max,t;
    while (scanf("%d",&n))
    {
        if (n==0)
        {
            break;
        }
        max=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t);
            if (t>max)
            {
                max=t;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
