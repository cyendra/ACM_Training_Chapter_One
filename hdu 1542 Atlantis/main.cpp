#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=22222;

struct Seg{
    double l,r,h;
    int s;
    Seg(){}
    Seg(double a,double b,double c,int d):l(a),r(b),h(c),s(d){}
    bool operator < (const Seg& cmp) const
    {
        return h<cmp.h;
    }
}a[N];
double X[N];

struct TREE{
    int l;
    int r;
    int cnt;
    double sum;
}tree[N*4];

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].cnt=0;
    tree[root].sum=0;
    if (l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
}

void push_up(int root)
{
    if (tree[root].cnt)
    {
        tree[root].sum=X[tree[root].r+1]-X[tree[root].l];
    }
    else if (tree[root].l==tree[root].r)
    {
        tree[root].sum=0;
    }
    else
    {
        tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    }
}

void update(int root,int L,int R,int val)
{
    if (L<=tree[root].l&&R>=tree[root].r)
    {
        tree[root].cnt+=val;
        push_up(root);
        return;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if (L<=mid) update(root<<1,L,R,val);
    if (R>mid) update(root<<1|1,L,R,val);
    push_up(root);
}

int main()
{
    int n,m,k;
    double x1,y1,x2,y2,ret;
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        m=0;
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[m]=x1;
            a[m++]=Seg(x1,x2,y1,1);
            X[m]=x2;
            a[m++]=Seg(x1,x2,y2,-1);
        }
        sort(X,X+m);
        sort(a,a+m);
        k=1;
        for (int i=1;i<m;i++)
        {
            if (X[i]!=X[i-1]) X[k++]=X[i];
        }
        build(1,0,k-1);
        ret=0;
        for (int i=0;i<m-1;i++)
        {
            int l=lower_bound(X,X+k,a[i].l)-X;
            int r=lower_bound(X,X+k,a[i].r)-X-1;
            if (l<=r) update(1,l,r,a[i].s);
            ret+=tree[1].sum*(a[i+1].h-a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %0.2lf\n\n",cnt++,ret);
    }
    return 0;
}

/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=22222;

struct Seg{
    double l,r,h;
    int s;
    Seg(){}
    Seg(double a,double b,double c,int d):l(a),r(b),h(c),s(d){}
    bool operator < (const Seg& cmp) const
    {
        return h<cmp.h;
    }
}a[N];
double X[N];

struct TREE{
    int l;
    int r;
    int cnt;
    double sum;
}tree[N*4];

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    tree[root].cnt=0;
    tree[root].sum=0;
    if (l==r)
    {
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
}

void push_up(int root)
{
    if (tree[root].cnt)
    {
        tree[root].sum=X[tree[root].r+1-1]-X[tree[root].l-1];
    }
    else if (tree[root].l==tree[root].r)
    {
        tree[root].sum=0;
    }
    else
    {
        tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
    }
}

void update(int root,int L,int R,int val)
{
    if (L<=tree[root].l&&R>=tree[root].r)
    {
        tree[root].cnt+=val;
        push_up(root);
        return;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if (L<=mid) update(root<<1,L,R,val);
    if (R>mid) update(root<<1|1,L,R,val);
    push_up(root);
}

int main()
{
    int n,m,k;
    double x1,y1,x2,y2,ret;
    int cnt=1;
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        m=0;
        for (int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[m]=x1;
            a[m++]=Seg(x1,x2,y1,1);
            X[m]=x2;
            a[m++]=Seg(x1,x2,y2,-1);
        }
        sort(X,X+m);
        sort(a,a+m);
        k=1;
        for (int i=1;i<m;i++)
        {
            if (X[i]!=X[i-1]) X[k++]=X[i];
        }
        build(1,1,k);
        ret=0;
        for (int i=0;i<m-1;i++)
        {
            int l=lower_bound(X,X+k,a[i].l)-X+1;
            int r=lower_bound(X,X+k,a[i].r)-X+1-1;
            if (l<=r) update(1,l,r,a[i].s);
            ret+=tree[1].sum*(a[i+1].h-a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %0.2lf\n\n",cnt++,ret);
    }
    return 0;
}

*/
