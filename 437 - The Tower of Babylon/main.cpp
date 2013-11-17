#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct SCV{
    int x;
    int y;
    int high;
}a[1111];

int f[1111111];

bool cmp(SCV a,SCV b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int n,m;

int main()
{
    int cnt=1;
    int sum=0;
    int ans;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        m=0;
        sum=0;
        ans=0;
        for (int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            sum+=x+y+z;
            a[m].x=x;
            a[m].y=y;
            a[m].high=z;
            if (a[m].x<=a[m].y) swap(a[m].x,a[m].y);
            m++;
            a[m].x=x;
            a[m].y=z;
            a[m].high=y;
            if (a[m].x<=a[m].y) swap(a[m].x,a[m].y);
            m++;
            a[m].x=y;
            a[m].y=z;
            a[m].high=x;
            if (a[m].x<=a[m].y) swap(a[m].x,a[m].y);
            m++;
        }
        sort(a,a+m,cmp);
        for (int i=0;i<m;i++)
        {
            f[i]=a[i].high;
            for (int j=0;j<i;j++)
            {
                if (a[i].x>a[j].x&&a[i].y>a[j].y&&f[j]+a[i].high>f[i])
                {
                    f[i]=f[j]+a[i].high;
                }
            }
            if (f[i]>ans) ans=f[i];
        }
        printf("Case %d: maximum height = %d\n",cnt++,ans);
    }
    return 0;
}
