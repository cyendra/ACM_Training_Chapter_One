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
    long long sum;
    long long col;
} tree[N*4];

void push_up(int rt)
{
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}

void push_down(int rt,int m)
{
    if (tree[rt].col!=0)
    {
        tree[rt<<1].col+=tree[rt].col;
        tree[rt<<1|1].col+=tree[rt].col;
        tree[rt<<1].sum+=(long long)(m-(m/2))*tree[rt].col;
        tree[rt<<1|1].sum+=(long long)(m/2)*tree[rt].col;
        tree[rt].col=0;
    }
}

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].col=0;
    if(tree[root].l==tree[root].r)
    {
        tree[root].sum=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    push_up(root);
}

void update(int root,int L,int R,int val)
{
    if(L<=tree[root].l&&R>=tree[root].r)
    {
        tree[root].col+=val;
        tree[root].sum+=(long long)val*(tree[root].r-tree[root].l+1);
        return;
    }
    push_down(root,tree[root].r-tree[root].l+1);
    int mid=(tree[root].l+tree[root].r)/2;
    if (L<=mid)
        update(root<<1,L,R,val);
    if (R>mid)
        update(root<<1|1,L,R,val);
    push_up(root);
}


long long query(int root,int L,int R)
{
    if(L<=tree[root].l&&R>=tree[root].r)
        return tree[root].sum;
    push_down(root,tree[root].r-tree[root].l+1);
    int mid=(tree[root].l+ tree[root].r)/2;
    long long ret=0;
    if(L<=mid) ret+=query(root<<1,L,R);
    if(R>mid) ret+=query(root<<1|1,L,R);
    return ret;
}


int main()
{
    int n,q;
    char s[2];
    scanf("%d%d",&n,&q);
    for (int i=1; i<=n; i++) scanf("%d",&num[i]);
    build(1,1,n);
    while (q--)
    {
        int x,y,z;
        scanf("%s",s);
        if (s[0]=='Q')
        {
            scanf("%d%d",&x,&y);
            printf("%I64d\n",query(1,x,y));
        }
        else if (s[0]=='C')
        {
            scanf("%d%d%d",&x,&y,&z);
            update(1,x,y,z);
        }
    }
    return 0;
}

