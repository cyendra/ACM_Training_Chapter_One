#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int mn=10000000;

int n,m;
int p[11000000];
bool v[11000000];
int a[11000000];
void make_set(int x);
int find_set(int x);
void union_set(int x,int y);
void init();

void init()
{
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    n=0;
    for (int i=1;i<=mn;i++) make_set(i);
}

void make_set(int x)
{
    p[x]=x;
}

int find_set(int x)
{
    if ( p[x]==x ) return x;
    else
    {
        int u=find_set(p[x]);
        p[x]=u;
        return u;
    }
}

void union_set(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    p[y]=x;
}

int main()
{
    int x,y;
    while ( scanf("%d",&m)!=EOF )
    {
        init();
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x]=true;
            v[y]=true;
            if (x>n) n=x;
            if (y>n) n=y;
            union_set(x,y);
        }
        //for (int i=1;i<=n;i++) cout<<p[i]<<" ";cout<<endl;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if ( v[i] )
            {
                a[find_set(i)]++;
                if ( a[find_set(i)]>ans ) ans=a[find_set(i)];
            }
        }
        if (n==0) printf("1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
