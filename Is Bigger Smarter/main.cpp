#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct EL{
    int x;
    int y;
    int id;
}a[11111];

bool cmp(EL a,EL b)
{
    if (a.x==b.x) return a.id<b.id;
    return a.x<b.x;
}

int n;
int f[11111]={0};
int p[11111]={0};
int ans[11111]={0};
int cnt;

int main()
{
    n=1;
    while (~scanf("%d%d",&a[n].x,&a[n].y)){a[n].id=n;n++;}
    n--;
    sort(a+1,a+n+1,cmp);
    int mx=0;
    int ww=0;
    //for (int i=1;i<=n;i++){cerr<<a[i].x<<" "<<a[i].y<<" "<<a[i].id<<endl;}
    for (int i=1;i<=n;i++)
    {
        f[i]=1;
        p[i]=0;
        for (int k=1;k<i;k++)
        {
            if (a[i].y<a[k].y&&a[i].x>a[k].x&&f[k]+1>f[i])
            {
                f[i]=f[k]+1;
                p[i]=k;
            }
        }
        if (f[i]>mx)
        {
            mx=f[i];
            ww=i;
        }
    }
    //for (int i=1;i<=n;i++) cerr<<f[i]<<" ";cerr<<endl;
    printf("%d\n",mx);
    cnt=0;
    while (ww!=0)
    {
        ans[cnt++]=a[ww].id;
        ww=p[ww];
    }
    for (int i=cnt-1;i>=0;i--)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
