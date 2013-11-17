#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 222222

using namespace std;

const int OO=1e9;

int num[N];

struct Tree
{
    int l;
    int r;
    int min;
} tree[N*4];

void push_up(int root)
{
    tree[root].min=min(tree[root<<1].min,tree[root<<1|1].min);
}

void build(int root,int l,int r)
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)
    {
        tree[root].min=num[l];
        return;
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    push_up(root);
}
void update(int root,int pos,int val)
{
    if(tree[root].l==tree[root].r)
    {
        tree[root].min=val;
        return;
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if(pos<=mid)
        update(root<<1,pos,val);
    else
        update(root<<1|1,pos,val);
    push_up(root);
}
int query(int root,int L,int R)
{
    if(L<=tree[root].l&&R>=tree[root].r)
        return tree[root].min;
    int mid=(tree[root].l+tree[root].r)/2,ret=OO;
    if(L<=mid) ret=min(ret,query(root<<1,L,R));
    if(R>mid) ret=min(ret,query(root<<1|1,L,R));
    return ret;
}

int main()
{
    int n,q,x,y;
    int stk[1111];
    int cnt;
    char s[11];
    while (~scanf("%d%d",&n,&q))
    {
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
        }
        build(1,1,n);
        while (q--)
        {
            scanf("%6s",s);
            if (s[0]=='q')
            {
                scanf("%d,%d)",&x,&y);
                printf("%d\n",query(1,x,y));
                //cerr<<x<<" "<<y;
            }
            if (s[0]=='s')
            {
                char c;
                int rm;
                cnt=0;
                while (scanf("%d%c",&x,&c))
                {
                    stk[cnt++]=x;
                    if (cnt==1)
                    {
                        rm=num[stk[0]];
                    }
                    else
                    {
                        num[stk[cnt-2]]=num[stk[cnt-1]];
                        update(1,stk[cnt-2],num[stk[cnt-2]]);
                    }
                    if (c!=',') break;
                }
                num[stk[cnt-1]]=rm;
                update(1,stk[cnt-1],num[stk[cnt-1]]);
            }
        }
    }
    return 0;
}

