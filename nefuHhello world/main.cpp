#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct coco{
    int x;
    int y;
    int id;
}a[1111],ans[1111];
int n;

bool cmp1(coco a,coco b)
{
    if (a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x<b.x;
}

bool cmp2(coco a,coco b)
{
    return a.id<b.id;
}

int main()
{
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp1);
        bool ok;
        for (int i=1;i<=n;i++)
        {
            ok=false;
            for (int j=i+1;j<=n;j++)
            {
                if (a[j].x>a[i].x&&a[j].y>a[i].y)
                {
                    ans[a[i].id]=a[j];
                    ok=true;
                    break;
                }
            }
            if (!ok)
            {
                ans[a[i].id].x=-1;
                ans[a[i].id].y=-1;
            }
        }
        printf("Case %d:\n",cnt++);
        for (int i=1;i<=n;i++)
        {
            printf("%d %d\n",ans[i].x,ans[i].y);
        }
        printf("\n");
    }
    return 0;
}
