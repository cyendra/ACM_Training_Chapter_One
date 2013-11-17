#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[500010];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    int n,m,t,ans;
    int r,l,d;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        for (int i=0; i<m; i++)
        {
            scanf("%d",&t);
            l=0;
            r=n-1;
            while (l<=r)
            {
                d=(l+r)/2;
                if (a[d]==t)
                {
                    break;
                }
                if (a[d]>t)
                {
                    l=d+1;
                }
                else if (a[d]<t)
                {
                    r=d-1;
                }
            }
            printf("%d\n",d+1);
        }
    }
    return 0;
}
