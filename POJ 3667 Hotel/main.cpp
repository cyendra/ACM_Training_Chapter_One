#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 555555

using namespace std;

const int OO=1e9;

queue<int>que;

struct Tree
{
    int l;
    int r;
    int num;
    int msum;
    int lsum;
    int rsum;
    int set;
} tree[N*4];

void push_up(int root)
{
    tree[root].lsum=tree[root<<1].lsum;
    tree[root].rsum=tree[root<<1|1].rsum;
    if (tree[root].lsum==tree[root<<1].num)
    {
        tree[root].lsum+=tree[root<<1|1].lsum;
    }
    if (tree[root].rsum==tree[root<<1|1].num)
    {
        tree[root].rsum+=tree[root<<1].rsum;
    }
    tree[root].msum=max( tree[root<<1].rsum+tree[root<<1|1].lsum, max(tree[root<<1].msum,tree[root<<1|1].msum) );
}

void push_down(int root)
{
    if (tree[root].set!=-1)
    {
        tree[root<<1].set=tree[root<<1|1].set=tree[root].set;
        if (tree[root].set==1)
        {
            tree[root<<1].lsum=tree[root<<1].rsum=tree[root<<1].msum=0;
            tree[root<<1|1].lsum=tree[root<<1|1].rsum=tree[root<<1|1].msum=0;
        }
        if (tree[root].set==0)
        {
            tree[root<<1].lsum=tree[root<<1].rsum=tree[root<<1].msum=tree[root<<1].num;
            tree[root<<1|1].lsum=tree[root<<1|1].rsum=tree[root<<1|1].msum=tree[root<<1|1].num;
        }
        tree[root].set=-1;
    }
}

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].num=r-l+1;
    tree[root].lsum=tree[root].rsum=tree[root].msum=r-l+1;
    tree[root].set=-1;
    if(tree[root].l==tree[root].r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
}

void update(int root,int L,int R,int val)
{
    if(L<=tree[root].l&&R>=tree[root].r)
    {
        if (val==1)
        {
            tree[root].lsum=tree[root].rsum=tree[root].msum=0;
        }
        if (val==0)
        {
            tree[root].lsum=tree[root].rsum=tree[root].msum=tree[root].num;
        }
        tree[root].set=val;
        return;
    }
    push_down(root);
    int mid=(tree[root].l+tree[root].r)/2;
    if(L<=mid)
        update(root<<1,L,R,val);
    if (R>mid)
        update(root<<1|1,L,R,val);
    push_up(root);
}

int query(int root,int w)
{
    if(tree[root].l==tree[root].r)
    {
        return tree[root].l;
    }
    push_down(root);
    int mid=(tree[root].l+tree[root].r)/2;
    if (tree[root<<1].msum>=w) return query(root<<1,w);
    else if(tree[root<<1].rsum+tree[root<<1|1].lsum>=w) return mid-tree[root<<1].rsum+1;
    return query(root<<1|1,w);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,1,n);
    while (m--)
    {
        int op,a,b;
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d",&a);
            if (tree[1].msum<a) puts("0");
            else
            {
                int p=query(1,a);
                printf("%d\n",p);
                update(1,p,p+a-1,1);
            }
        }
        else
        {
            scanf("%d%d",&a,&b);
            update(1,a,a+b-1,0);
        }
    }
    return 0;
}
