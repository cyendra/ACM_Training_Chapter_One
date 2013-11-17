#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int OO=1e9;
const int maxn=1111;

struct Fruits{
    int x;
    int y;
};

int n,T;
int f[maxn];
Fruits a[maxn];

bool cmp(Fruits a,Fruits b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    scanf("%d",&T);
    int cas=1;
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
        sort(a+1,a+n+1,cmp);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int cut=0;
            if (i+1<=n&&a[i].x==a[i+1].x) continue;//why???????
            for (int j=i;j>=1;j--)
            {
                if (a[j].y>=a[i].x) cut++;
                if (cut>2) f[i]=max(f[i],f[j-1]+cut);
                else f[i]=max(f[i],f[j-1]);
            }
            ans=max(ans,f[i]);
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
