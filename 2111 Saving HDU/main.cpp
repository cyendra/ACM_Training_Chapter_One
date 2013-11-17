#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct{
    int p;
    int m;
}POINT;
POINT a[101];

bool cmp(POINT a,POINT b)
{
    if (a.p>b.p)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n,v;

    int ans;

    while (scanf("%d",&v))
    {
        if (v==0)
        {
            break;
        }
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].p,&a[i].m);
        }
        sort(a,a+n,cmp);
        ans=0;
        for (int i=0;(i<n)&&(v>0);i++)
        {
            if ( v>= a[i].m )
            {
                v=v-a[i].m;
                ans=ans+a[i].m * a[i].p;
            }
            else
            {
                ans=ans + a[i].p * v;
                v=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
