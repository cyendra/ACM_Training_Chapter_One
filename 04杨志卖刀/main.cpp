#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct
{
    int dao;
    int mi;
    double v;
} HERO;

bool cmp(HERO a,HERO b)
{
    if (a.v>b.v)
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
    int m,n,lasti;
    double ans;
    HERO a[10000];
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        for (int i=0; i<n; i++)
        {
            scanf("%d%d",&a[i].dao,&a[i].mi);
            a[i].v=(double)a[i].mi / (double)a[i].dao;
        }
        sort(a,a+n,cmp);
        ans=0;
        for (int i=0; i<n; i++)
        {
            if (m-a[i].dao>=0)
            {
                ans+=a[i].mi;
                m-=a[i].dao;
            }
            else
            {
                lasti=i;
                break;
            }
        }
        if (lasti<n)
        {
            for (int i=1; i<=m; i++)
            {
                ans+=a[lasti].v;
            }
        }
        printf("%0.2f\n",ans);
    }
    return 0;
}
