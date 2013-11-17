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
    int sum;
    int col;
} tree[N*4];

void push_up(int rt)
{
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}

void push_down(int rt,int m)
{
    if (tree[rt].col>0)
    {
        tree[rt<<1].col=tree[rt<<1|1].col=tree[rt].col;
        tree[rt<<1].sum=(m-(m/2))*tree[rt].col;
        tree[rt<<1|1].sum=(m/2)*tree[rt].col;
        tree[rt].col=0;
    }
}

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].sum=1;
    tree[root].col=0;
    if(tree[root].l==tree[root].r)
    {
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
        tree[root].col=val;
        tree[root].sum=val*(tree[root].r-tree[root].l+1);
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

int main()
{
    int n,q,T;
    scanf("%d",&T);
    for (int lp=1;lp<=T;lp++)
    {
        scanf("%d",&n);
        build(1,1,n);
        scanf("%d",&q);
        while (q--)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            update(1,x,y,z);
        }
        int ans=tree[1].sum;
        printf("Case %d: The total value of the hook is %d.\n",lp,ans);
    }
    return 0;
}

