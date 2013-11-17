#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int maxn;
int n;
int tree[111111];

struct MANYCOW{
    int x;
    int y;
    int d;
}cow[111111];
int m;
int ans[111111];

bool cmp(MANYCOW a,MANYCOW b)
{
    if (a.y!=b.y) return a.y<b.y;
    return a.x>b.x;
}

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int d)
{
    while (i<=maxn)
    {
        tree[i]+=d;
        i+=lowbit(i);
    }
}

int query(int i)
{
    int ret=0;
    while (i>0)
    {
        ret+=tree[i];
        i-=lowbit(i);
    }
    return ret;
}

int main()
{
    int s,e;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        m=0;
        maxn=0;
        memset(tree,0,sizeof(tree));
        //memset(cow,0,sizeof(cow));
        //memset(ans,0,sizeof(ans));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&s,&e);
            cow[m].d=i;
            cow[m].x=s+1;
            cow[m++].y=e+1;
            if (e+1>maxn) maxn=e+1;
        }
        //scanf("%d",&e);
        sort(cow,cow+m,cmp);
        for (int i=n-1;i>=0;i--)
        {
            if (i!=n-1&&cow[i].x==cow[i+1].x&&cow[i].y==cow[i+1].y)
            {
                ans[cow[i].d]=ans[cow[i+1].d];
            }
            else
            {
                ans[cow[i].d]=query(cow[i].x);
            }
            updata(cow[i].x,1);
        }
        for (int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}
