#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int maxn=100000;
int n;

struct CAR{
    int x;
    long long spd;
    int y;
}a[111111];

struct LS{
    int x;
    long long y;
}lss[111111];

bool cmp1(LS a,LS b)
{
    return a.y<b.y;
}

bool cmp2(CAR a,CAR b)
{
    if (a.x==b.x)
    {
        return a.y<b.y;
    }
    return a.x>b.x;
}

int tree[111111];

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int val)
{
    for (int i=x;i<=maxn;i+=lowbit(i))
    {
        tree[i]+=val;
    }
}

int query(int x)
{
    int ret=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        ret+=tree[i];
    }
    return ret;
}

int main()
{
    while (~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(lss,0,sizeof(lss));
        memset(tree,0,sizeof(tree));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%I64d",&a[i].x,&a[i].spd);
            lss[i].x=i;
            lss[i].y=a[i].spd;
        }

        //ÀëÉ¢
        sort(lss+1,lss+n+1,cmp1);
        int cnt=0;
        int last=-65535;
        for (int i=1;i<=n;i++)
        {
            if (lss[i].y!=last)
            {
                last=lss[i].y;
                cnt++;
                a[lss[i].x].y=cnt;
            }
            else
            {
                a[lss[i].x].y=cnt;
            }
        }

        maxn=0;
        for (int i=1;i<=n;i++) maxn=max(maxn,a[i].y);
        maxn++;

        sort(a+1,a+n+1,cmp2);

        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=query(a[i].y-1);
            update(a[i].y,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

