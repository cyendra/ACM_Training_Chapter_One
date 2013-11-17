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
} tree[N*4];

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
    tree[root].max=max(tree[root<<1].max,tree[root<<1|1].max);
}
void update(int root,int pos,int val)
{
    if(tree[root].l==tree[root].r)
    {
        tree[root].max=val;
        return;
    }
    int mid=(tree[root].l+ tree[root].r)/2;
    if(pos<=mid)
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    tree[root].max = max(tree[root<<1].max,tree[root<<1|1].max);
}
int query(int root,int L,int R)
{
    if(L<=tree[root].l&&R>=tree[root].r)
        return tree[root].max;
    int mid=(tree[root].l+ tree[root].r)/2,ret=0;
    if(L<=mid) ret=max(ret,query(root<<1,L,R));
    if(R>mid) ret=max(ret,query(root<<1|1,L,R));
    return ret;
}

int main()
{
    int n,m,x1,x2;
    char s[2];
    while (~scanf("%d%d",&n,&m))
    {
        for (int i=1;i<=n;i++) scanf("%d",&num[i]);
        build(1,1,n);
        while (m--)
        {
            scanf("%s%d%d",s,&x1,&x2);
            if (s[0]=='Q') printf("%d\n",query(1,x1,x2));
            else update(1,x1,x2);
        }
    }
    return 0;
}

