#include <iostream>
#include <cstring>
#include <cstdio>
#define N 50005
using namespace std;

int num[N];

typedef struct{
    int l;
    int r;
    int sum;
}TREE;
TREE tree[N*4];

void build(int root,int l,int r);
void updata(int root,int pos,int val);
int query(int root,int l,int r);

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    if (tree[root].l==tree[root].r)
    {
        tree[root].sum=num[l];
        return;
    }
    int mid;
    mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

void updata(int root,int pos,int val)
{
    if ( tree[root].l==tree[root].r )
    {
        tree[root].sum=val;
        return;
    }
    int mid;
    mid=(tree[root].l+tree[root].r)/2;
    if ( pos<=mid )
    {
        updata(root<<1,pos,val);
    }
    else
    {
        updata(root<<1|1,pos,val);
    }
    tree[root].sum=tree[root<<1].sum+tree[root<<1|1].sum;
}

int query(int root,int L,int R)
{
    if ( L<=tree[root].l && R>=tree[root].r )
    {
        return tree[root].sum;
    }
    int mid,ret;
    mid=(tree[root].l+tree[root].r)/2;
    ret=0;
    if ( L<=mid ) ret+=query(root<<1,L,R);
    if ( R>mid ) ret+=query(root<<1|1,L,R);
    return ret;
}

int main()
{
    int n,lp,a,b,tmp;
    char str[10];
    scanf("%d",&lp);
    for (int loop=1;loop<=lp;loop++)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",loop);
        while ( scanf("%s",str)!=EOF && strcmp( str , "End" )!=0 )
        {
            scanf("%d%d",&a,&b);
            if ( strcmp( str , "Query" )==0 )
            {
                if (a>b)
                {
                    tmp=a;
                    a=b;
                    b=tmp;
                }
                printf("%d\n",query(1,a,b));
            }
            else if ( strcmp( str , "Add" )==0 )
            {
                num[a]+=b;
                updata(1,a,num[a]);
            }
            else if ( strcmp( str , "Sub" )==0 )
            {
                num[a]-=b;
                updata(1,a,num[a]);
            }
        }
    }
    return 0;
}
