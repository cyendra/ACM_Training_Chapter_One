#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
    int d;
    int v;
}HERO;

HERO a[1010];
bool ip[1010];

int T,n;

bool cmp(HERO a,HERO b)
{
    if (a.d==b.d)
    {
        return a.v<b.v;
    }
    else
    {
        return a.d<b.d;
    }
}

int main()
{
    int ans,now,mn,mni;
    scanf("%d",&T);
    for (int loop=1;loop<=T;loop++)
    {
        ans=0;
        now=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i].d);
        }
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i].v);
            ip[i]=false;
            //ans=ans+a[i].v;
        }
        sort(a,a+n,cmp);

        for (int i=0;i<n;i++)
        {
            ip[i]=true;
            if ( now<a[i].d )
            {
                now++;
                //ans-=a[i].v;
            }
            else
            {
                mn=9999999;
                for (int j=0;j<=i;j++)
                {
                    if (ip[j]==true && a[j].v<mn )
                    {
                        mn=a[j].v;
                        mni=j;
                    }
                }
                ip[mni]=false;
                ans+=a[mni].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
