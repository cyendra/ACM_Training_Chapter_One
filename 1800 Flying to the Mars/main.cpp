#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

//map <int> mp;

int main()
{
    int n,ans,tmp,num;
    int a[3001];
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        tmp=-1;
        num=0;
        ans=0;
        for (int i=0;i<n;i++)
        {
            if ( tmp!=a[i] )
            {
                if (num>ans)
                {
                    ans=num;
                }
                tmp=a[i];
                num=1;
            }
            else
            {
                num++;
            }
        }
        if (num>ans)
        {
            ans=num;
        }
        printf("%d\n",ans);
    }
    return 0;
}
