#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 222222

using namespace std;

int num[N];

struct Tree
{
    int l;
    int r;
    int max;
}tree[N*4];

void push_up(int root)
{
    tree[root].max=max(tree[root<<1].max,tree[root<<1|1].max);
}

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)
    {
        tree[root].max=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    push_up(root);
}

int updata(int root,int val)
{
    int ret=0;
    if (tree[root].l==tree[root].r)
    {
        tree[root].max-=val;
        return tree[root].l;
    }
    if (tree[root<<1].max>=val)
    {
        ret=updata(root<<1,val);
    }
    else
    {
        ret=updata(root<<1|1,val);
    }
    push_up(root);
    return ret;
}

int main()
{
    int h,w,n,t;
    while (~scanf("%d%d%d",&h,&w,&n))
    {
        if (h>n) h=n;
        for (int i=1;i<=h;i++) num[i]=w;
        build(1,1,h);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            if (tree[1].max<t) printf("-1\n");
            else printf("%d\n",updata(1,t));
        }
    }
    return 0;
}
