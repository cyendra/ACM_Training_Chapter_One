#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int t,m,n,c;
    int a[31];
    __int64 bow[31],ans;
    bow[0]=0;
    bow[1]=1;
    for (int i=2;i<=30;i++)
    {
        bow[i]=bow[i-1]*2;
    }
    scanf("%d",&t);
    for (int loop=0;loop<t;loop++)
    {
        scanf("%d%d",&m,&n);
        c=-m;
        ans=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if ( (a[i]==1) && (c<0) )
            {
                c=0;
            }
            else
            {
                c++;
            }
            if (c>0)
            {
                ans+=bow[c];
            }
        }
        printf("%I64d RMB\n",ans*10000);
    }
    return 0;
}
