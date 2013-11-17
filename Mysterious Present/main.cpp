#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef struct{
    int w;
    int h;
    int num;
}HERO;

typedef struct{
    int v;
    int num;
    int last;
}DPDATA;

int n,minw,minh;
HERO a[5001];
DPDATA f[5001];

int ans,ansf;

bool cmp(HERO x,HERO y)
{
    if ( x.w==y.w )
    {
        return x.h>y.h;
    }
    else
    {
        return x.w>y.w;
    }
}

int main()
{
    int p;
    scanf("%d%d%d",&n,&minw,&minh);
    p=1;
    a[0].w=9999999;
    a[0].h=9999999;
    a[0].num=0;
    f[0].v=0;
    f[0].last=0;
    f[0].num=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[p].w,&a[p].h);
        if ( a[p].w>minw && a[p].h>minh )
        {
            a[p].num=i;
            f[p].v=0;
            f[p].last=0;
            f[p].num=0;
            p++;
        }
    }
    n=p;


    sort(a+1,a+n,cmp);

    /*
    for (int i=1;i<n;i++)
    {
        printf("i=%d w=%d h=%d\n",i,a[i].w,a[i].h);
    }
    cout << endl;
    */

    ans=0;
    ansf=-1;
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if ( a[i].w<a[j].w && a[i].h<a[j].h && f[j].v+1>f[i].v )
            {
                f[i].v=f[j].v+1;
                f[i].num=a[i].num;
                f[i].last=j;
            }
        }
        if ( f[i].v>ans )
        {
            ans=f[i].v;
            ansf=i;
        }
    }
    if (n==1)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",ans);
        p=ansf;
        while ( p!=0 )
        {
            printf("%d ",f[p].num);
            p=f[p].last;
        }
        printf("\n");
    }
    return 0;
}
