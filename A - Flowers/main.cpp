#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn=211111;

int n,m;
int s[maxn],t[maxn];
int b[maxn];
int tree[maxn];
int q[maxn];
int ans[maxn];
int mn,nn;

int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int val)
{
    for (int i=x;i<=mn;i+=lowbit(i))
    {
        tree[i]+=val;
    }
}

int query(int x)
{
    int ret=0;
    for (int i=x;i>0;i-=lowbit(i))
    {
        ret+=tree[i];
    }
    return ret;
}

int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while (T--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d%d",&n,&m);
        nn=1;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&s[i],&t[i]);
            b[nn++]=s[i];
            b[nn++]=t[i];
        }
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&q[i]);
            b[nn++]=q[i];
        }
        sort(b+1,b+nn);
        mn=1;
        for (int i=2;i<nn;i++)
        {
            if (b[i]!=b[i-1]) b[++mn]=b[i];
        }
        //for (int i=1;i<=mn;i++) cerr<<b[i]<<" ";cerr<<endl;
        for (int i=1;i<=n;i++)
        {
            int l=lower_bound(b+1,b+mn+1,s[i])-b;
            int r=lower_bound(b+1,b+mn+1,t[i])-b;
            //cerr<<"l="<<l<<" r="<<r<<endl;
            add(l,1);
            add(r+1,-1);
        }
        printf("Case #%d:\n",++cnt);
        for (int i=1;i<=m;i++)
        {
            int l=lower_bound(b+1,b+mn+1,q[i])-b;
            printf("%d\n",query(l));
        }
    }
    return 0;
}
