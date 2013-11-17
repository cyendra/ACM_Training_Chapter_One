#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct
{
    int p;
    int r;
} HERO;

HERO a[500050];
int f[500050];
bool cmp(HERO a,HERO b);

bool cmp(HERO a,HERO b)
{
    return a.p < b.p;
}

int main()
{
    int n,ans,loop,len,low,high,mid;
    loop=0;
    while (scanf("%d",&n)!=EOF)
    {
        loop++;
        a[0].p=0;
        a[0].r=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d%d",&a[i].p,&a[i].r);
        }
        sort(a+1,a+n+1,cmp);
        //¼ìÑé
        //for (int i=0;i<n;i++)
        //{
        //    printf("%d %d\n",a[i].p,a[i].r);
        //}

        //¶þ·Ö
        len=1;

        f[1]=a[1].r;

        for (int i=2; i<=n; i++)
        {
            low=1;
            high=len;
            while ( low<=high )
            {
                mid=(low+high)/2;
                if (a[i].r> f[mid])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }

            }
            f[low]=a[i].r;
            if (low>len)
            {
                len=low;
            }
        }
        if (len==1)
        {
            printf("Case %d:\n",loop);
            printf("My king, at most %d road can be built.\n\n",len);
        }
        else
        {
            printf("Case %d:\n",loop);
            printf("My king, at most %d roads can be built.\n\n",len);
        }

    }
    return 0;
}
