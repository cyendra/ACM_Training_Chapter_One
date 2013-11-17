#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int a[500];

bool cmp(int a,int b)
{
    if (a>b)
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
    int m,n,t,s1,s2,ans;
    scanf("%d",&m);
    for (int loop=1;loop<=m;loop++)
    {
        scanf("%d",&n);
        if (n==1)
        {
            scanf("%d",&a[0]);
            printf("0\n");
        }
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        t=n/2;
        s1=0;
        for (int i=0;i<n;i++)
        {
            s1+=abs(a[i]-a[t]);
        }
        s2=0;
        t=n/2-1;
        for (int i=0;i<n;i++)
        {
            s2+=abs(a[i]-a[t]);
        }
        if (s1<s2)
        {
            ans=s1;
        }
        else
        {
            ans=s2;
        }
        printf("%d\n",ans);
    }
    return 0;
}
