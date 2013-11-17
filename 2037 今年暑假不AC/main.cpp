#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int ts;
    int te;
}HERO;

bool cmp(HERO a,HERO b)
{
    return ( a.te<b.te );
}

int main()
{
    int n,l,ans;
    HERO a[101];
    //scanf("%d",&n);
    while (scanf("%d",&n)!=0 && n!=0)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].ts,&a[i].te);
        }
        sort( a,a+n,cmp );
        l=0;
        ans=0;
        for (int i=0;i<n;i++)
        {
            if ( a[i].ts >= l)
            {
                ans++;
                l=a[i].te;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
