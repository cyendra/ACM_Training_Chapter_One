#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n,m;
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
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        scanf("%d",&m);
        for (int i=1;i<=n;i++) make_set(i);
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            union_set(x,y);
            //for (int i=1;i<=n;i++) cerr<<p[i]<<" ";
            //cerr<<endl;
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (p[i]==i) ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
