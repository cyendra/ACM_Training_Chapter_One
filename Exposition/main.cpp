#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 100100
#define OO 9999999

using namespace std;

typedef struct{
    int l;
    int r;
    int max;
    int min;
}TREETYPE;

TREETYPE tree[MAXN*4];
int num[MAXN];
int n,K;

void build(int root,int l,int r);
int querymax(int root,int l,int r);
int querymin(int root,int l,int r);

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    if ( l==r )
    {
        tree[root].max=num[l];
        tree[root].min=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    tree[root].max=max( tree[root<<1].max , tree[root<<1|1].max );
    tree[root].min=min( tree[root<<1].min , tree[root<<1|1].min );
}

int querymax(int root,int l,int r)
{
    if ( l<=tree[root].l&&r>=tree[root].r )
    {
        return tree[root].max;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    int ret=0;
    if ( l<=mid ) ret=max( ret , querymax(root<<1,l,r) );
    if ( r>mid ) ret=max( ret , querymax(root<<1|1,l,r) );
    return ret;
}

int querymin(int root,int l,int r)
{
    if ( l<=tree[root].l&&r>=tree[root].r )
    {
        return tree[root].min;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    int ret=OO;
    if ( l<=mid ) ret=min( ret , querymin(root<<1,l,r) );
    if ( r>mid ) ret=min( ret , querymin(root<<1|1,l,r) );
    return ret;
}

int main()
{
    int ans=0,t=1;
    int pl[MAXN],pr[MAXN];
    int i,j;
    scanf("%d%d",&n,&K);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
    }
    build(1,1,n);
    for (i=1,j=1;j<=n;i++)
    {
        if (j<i) j=i;
        while ( j<=n && ( querymax(1,i,j)-querymin(1,i,j)<=K ) ) j++;
        if ( j-i>ans )
        {
            ans=j-i;
            pl[0]=i;
            pr[0]=j-1;
            t=1;
        }
        else if (j-i==ans)
        {
            pl[t]=i;
            pr[t]=j-1;
            t++;
        }
    }
    printf("%d %d\n",ans,t);
    for (int i=0;i<t;i++)
    {
        printf("%d %d\n",pl[i],pr[i]);
    }
    return 0;
}
