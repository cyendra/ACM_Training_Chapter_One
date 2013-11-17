#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=222222;

struct Tree
{
    int l;
    int r;
    int col;
} tree[N*4];

bool hash[N];

int it_x[N];
int it_y[N];
int a[N*4];

void push_up(int rt)
{
    ;
}

void push_down(int rt)
{
    if (tree[rt].col>0)
    {
        tree[rt<<1].col=tree[rt<<1|1].col=tree[rt].col;
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
        return;
    }
    push_down(root);
    int mid=(tree[root].l+tree[root].r)/2;
    if (L<=mid)
        update(root<<1,L,R,val);
    if (R>mid)
        update(root<<1|1,L,R,val);
    push_up(root);
}

void query(int root)
{
    if (tree[root].col!=0)
    {
        hash[ tree[root].col ]=true;
        return;
    }
    if (tree[root].l==tree[root].r) return;
    query(root<<1);
    query(root<<1|1);
}


int search(int key,int a[],int n)
{
    int l=0,r=n-1;
    while (l<=r)
    {
        int m=(l+r)/2;
        if (a[m]==key) return m;
        if (a[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main()
{
    int T,n,m,nn;
    scanf("%d",&T);
    while (T--)
    {
        memset(hash,0,sizeof(hash));
        nn=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&it_x[i],&it_y[i]);
            a[nn++]=it_x[i];
            a[nn++]=it_y[i];
        }
        sort(a,a+nn);
        m=1;
        for (int i=1;i<nn;i++)
        {
            if (a[i]!=a[i-1]) a[m++]=a[i];
        }
        for (int i=m-1;i>0;i--)
        {
            if (a[i]!=a[i-1]+1) a[m++]=a[i-1]+1;
        }
        sort(a,a+m);
        build(1,1,m);
        for (int i=1;i<=n;i++)
        {
            //int x=search(it_x[i],a,m)+1;
            //int y=search(it_y[i],a,m)+1;
            int x=lower_bound(a,a+m,it_x[i])-a+1;
            int y=lower_bound(a,a+m,it_y[i])-a+1;
            update(1,x,y,i);
        }
        query(1);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (hash[i]) ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=222222;

int num[N];

struct Tree
{
    int l;
    int r;
    int col;
} tree[N*4];

bool hash[N];

void push_up(int rt)
{
    ;
}

void push_down(int rt)
{
    if (tree[rt].col>0)
    {
        tree[rt<<1].col=tree[rt<<1|1].col=tree[rt].col;
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
        return;
    }
    push_down(root);
    int mid=(tree[root].l+tree[root].r)/2;
    if (L<=mid)
        update(root<<1,L,R,val);
    if (R>mid)
        update(root<<1|1,L,R,val);
    push_up(root);
}

void query(int root)
{
    if (tree[root].col!=0)
    {
        hash[ tree[root].col ]=true;
        return;
    }
    if (tree[root].l==tree[root].r) return;
    query(root<<1);
    query(root<<1|1);
}

struct DATA{
    int id;
    int fd;
    int d;
    bool x;
}a[N];

int it_x[N];
int it_y[N];

bool cmp1(DATA a,DATA b)
{
    if (a.fd^b.fd) return a.fd<b.fd;
    return !a.x;
}

bool cmp2(DATA a,DATA b)
{
    if (a.id^b.id) return a.id<b.id;
    return a.x;
}

int main()
{
    int T,c,n,m,cnt;
    scanf("%d",&T);
    while (T--)
    {
        memset(hash,0,sizeof(hash));
        m=0;
        c=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&it_x[i],&it_y[i]);
            a[m].id=i;
            a[m].fd=it_x[i];
            a[m].x=true;
            m++;
            a[m].id=i;
            a[m].fd=it_y[i];
            a[m].x=false;
            m++;
        }
        sort(a,a+m,cmp1);
        cnt=1;
        for (int i=0;i<m;i++)
        {
            a[i].d=cnt;
            c=max(c,a[i].d);
            if (a[i].fd!=a[i+1].fd) cnt+=2;
            if (a[i].fd+1==a[i+1].fd) cnt-=1;
        }
        sort(a,a+m,cmp2);
        for (int i=1;i<=c;i++)
        {
            num[i]=0;
        }
        build(1,1,c);
        for (int i=0;i<m;i+=2)
        {
            int x=a[i].d;
            int y=a[i+1].d;
            int id=a[i].id;
            update(1,x,y,id);
        }
        query(1);
        int ans=0;
        for (int i=1;i<=c;i++)
        {
            if (hash[i]) ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}
*/

