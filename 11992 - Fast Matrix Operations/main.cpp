#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 555555

using namespace std;
const int OO=1e9;
int num[30][N];
int _min,_max,_sum;

struct Tree
{
    int l;
    int r;
    int max;
    int min;
    int sum;
    int add;
    int set;
}big_tree[21][N*4];

void push_up(int root,Tree tree[])
{
    tree[root].max=max(tree[root<<1].max,tree[root<<1|1].max);
    tree[root].min=min(tree[root<<1].min,tree[root<<1|1].min);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

void push_down(int root,Tree tree[])
{
    if (tree[root].set!=-1)
    {
        if (tree[root].l!=tree[root].r)
        {
            //传递懒惰标记
            tree[root<<1].add=tree[root<<1|1].add=0;
            tree[root<<1].set=tree[root<<1|1].set=tree[root].set;
            //最更新大值
            tree[root<<1].max=tree[root<<1|1].max=tree[root].set;
            //更新最小值
            tree[root<<1].min=tree[root<<1|1].min=tree[root].set;
            //更新区间和
            tree[root<<1].sum=(tree[root<<1].r-tree[root<<1].l+1)*tree[root].set;
            tree[root<<1|1].sum=(tree[root<<1|1].r-tree[root<<1|1].l+1)*tree[root].set;
        }
        tree[root].set=-1;
    }
    if (tree[root].add>0)
    {
        if (tree[root].l!=tree[root].r)
        {
            //传递懒惰标记
            tree[root<<1].add+=tree[root].add;
            tree[root<<1|1].add+=tree[root].add;
            //更新最大值
            tree[root<<1].max+=tree[root].add;
            tree[root<<1|1].max+=tree[root].add;
            //更新最小值
            tree[root<<1].min+=tree[root].add;
            tree[root<<1|1].min+=tree[root].add;
            //更新区间和
            tree[root<<1].sum+=(tree[root<<1].r-tree[root<<1].l+1)*tree[root].add;
            tree[root<<1|1].sum+=(tree[root<<1|1].r-tree[root<<1|1].l+1)*tree[root].add;
        }
        tree[root].add=0;
    }
}

void build(int root,int l,int r,Tree tree[])
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)
    {
        tree[root].max=0;
        tree[root].min=0;
        tree[root].sum=0;
        tree[root].add=0;
        tree[root].set=-1;
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid,tree);
    build(root<<1|1,mid+1,r,tree);
    push_up(root,tree);
}

void update_add(int root,int L,int R,int val,Tree tree[])
{

    if(L<=tree[root].l&&R>=tree[root].r)
    {
        tree[root].add+=val;
        tree[root].max+=val;
        tree[root].min+=val;
        tree[root].sum+=(tree[root].r-tree[root].l+1)*val;
        return;
    }
    push_down(root,tree);
    int mid=(tree[root].l+tree[root].r)/2;
    if(L<=mid)
        update_add(root<<1,L,R,val,tree);
    if (R>mid)
        update_add(root<<1|1,L,R,val,tree);
    push_up(root,tree);
}

void update_set(int root,int L,int R,int val,Tree tree[])
{
    if(L<=tree[root].l&&R>=tree[root].r)
    {
        tree[root].set=val;
        tree[root].add=0;
        tree[root].max=val;
        tree[root].min=val;
        tree[root].sum=(tree[root].r-tree[root].l+1)*val;
        return;
    }
    push_down(root,tree);
    int mid=(tree[root].l+tree[root].r)/2;
    if(L<=mid)
        update_set(root<<1,L,R,val,tree);
    if (R>mid)
        update_set(root<<1|1,L,R,val,tree);
    push_up(root,tree);
}


void query(int root,int L,int R,Tree tree[])
{
    if(L<=tree[root].l&&R>=tree[root].r)
    {
        _min=min(_min,tree[root].min);
        _max=max(_max,tree[root].max);
        _sum+=tree[root].sum;
        return;
    }
    push_down(root,tree);
    int mid=(tree[root].l+tree[root].r)/2;
    if(L<=mid) query(root<<1,L,R,tree);
    if(R>mid) query(root<<1|1,L,R,tree);
}

int main()
{
    int r,c,m;
    while (~scanf("%d%d%d",&r,&c,&m))
    {
        int tp,x1,x2,y1,y2;
        for (int i=1;i<=r;i++)
        {
            build(1,1,c,big_tree[i]);
        }
        while (m--)
        {
            int v;
            scanf("%d%d%d%d%d",&tp,&x1,&y1,&x2,&y2);
            if (tp==1)
            {
                scanf("%d",&v);
                for (int i=x1;i<=x2;i++)
                {
                    update_add(1,y1,y2,v,big_tree[i]);
                }
            }
            if (tp==2)
            {
                scanf("%d",&v);
                for (int i=x1;i<=x2;i++)
                {
                    update_set(1,y1,y2,v,big_tree[i]);
                }
            }
            if (tp==3)
            {
                _max=0;
                _min=OO;
                _sum=0;
                for (int i=x1;i<=x2;i++)
                {
                    query(1,y1,y2,big_tree[i]);
                }
                printf("%d %d %d\n",_sum,_min,_max);
            }
        }
    }
    return 0;
}
