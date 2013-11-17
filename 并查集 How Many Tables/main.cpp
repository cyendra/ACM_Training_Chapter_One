#include <iostream>
#include <cstdio>

using namespace std;

int T;
int n,m;
int x,y;

int p[1111];
void make_set(int x);
int find_set(int x);
void union_set(int x,int y);

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
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) make_set(i);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            union_set(x,y);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (p[i]==i) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
