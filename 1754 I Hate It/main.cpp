#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 200100
using namespace std;

typedef struct{
    int l;
    int r;
    int max;
}BIGTREE;

BIGTREE tree[4*N];
int num[N];
int n,m;

void build(int root,int l,int r);
int query(int root,int l,int r);
void updata(int root,int pos,int val);

void build(int root,int l,int r)
{
    //printf("%d %d %d\n",root,l,r);
    tree[root].l=l;
    tree[root].r=r;
    if (l==r)
    {
        tree[root].max=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    tree[root].max=max( tree[root<<1].max , tree[root<<1|1].max );
}

int query(int root,int l,int r)
{
    if ( l<=tree[root].l && r>=tree[root].r )
    {
        return tree[root].max;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    int ret=0;
    if ( l<=mid )
    {
        ret=max( ret , query(root<<1,l,r) );
    }
    if ( r>mid )
    {
        ret=max( ret , query(root<<1|1,l,r) );
    }
    return ret;
}

void updata(int root,int pos,int val)
{
    if ( tree[root].l==tree[root].r )
    {
        tree[root].max=val;
        return;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if (pos<=mid)
    {
        updata(root<<1,pos,val);
    }
    else
    {
        updata(root<<1|1,pos,val);
    }
    tree[root].max=max( tree[root<<1].max , tree[root<<1|1].max );
}

int main()
{
    char qst[2];
    int a,b;
    while ( scanf("%d%d",&n,&m)!=EOF )
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        build(1,1,n);
        for (int j=1;j<=m;j++)
        {
            scanf("%s%d%d",qst,&a,&b);
            if (qst[0]=='Q')
            {
                printf("%d\n",query(1,a,b));
            }
            else if (qst[0]=='U')
            {
                num[a]=b;
                updata(1,a,b);
            }
        }
    }
    return 0;
}
