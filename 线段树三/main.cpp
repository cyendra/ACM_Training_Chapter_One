#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 50005
using namespace std;
int num[N];
struct Tree
{
    int l;
    int r;
    int sum;
} tree[N*4];
void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)
    {
        tree[root].sum=0;
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum;
}
void update(int root,int pos,int val)
{
    if(tree[root].l==tree[root].r)
    {
        tree[root].sum=val;
        return;
    }
    int mid=(tree[root].l+ tree[root].r)/2;
    if(pos<=mid)
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    tree[root].sum = tree[root<<1].sum+ tree[root<<1|1].sum;
}
int query(int root,int L,int R)
{
    if(L<=tree[root].l&&R>=tree[root].r)
        return tree[root].sum;
    int mid=(tree[root].l+ tree[root].r)/2,ret=0;
    if(L<=mid) ret+=query(root<<1,L,R);
    if(R>mid) ret+=query(root<<1|1,L,R);
    return ret;
}

int x[N];
int main()
{
    int n;
    int sum,ret;
    while (~scanf("%d",&n))
    {
        build(1,0,n-1);
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            sum+=query(1,x[i],n-1);
            update(1,x[i],1);
        }
        ret=sum;
        for (int i=0;i<n;i++)
        {
            sum+=n-x[i]-x[i]-1;
            if (sum<ret)
            {
                ret=sum;
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}
