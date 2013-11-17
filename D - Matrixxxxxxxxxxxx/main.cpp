#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=111111;
struct edgenode{
    int u,v,w;
}edges[maxn];
bool boom[maxn];
bool cmp(edgenode a,edgenode b)
{
    return a.w>b.w;
}

int p[maxn];
void make_set(int n)
{
    for (int i=0;i<=n;i++) p[i]=i;
}
int find_set(int x)
{
    if (x!=p[x]) p[x]=find_set(p[x]);
    return p[x];
}
void unin(int x,int y)
{
    bool ok=false;
    if (boom[x]||boom[y])
    {
        ok=true;
    }
    x=find_set(x);
    y=find_set(y);
    if (x!=y) p[x]=y;
    if (ok) boom[y]=true;
}
int n,k;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(boom,0,sizeof(boom));
        scanf("%d%d",&n,&k);
        make_set(n);
        for (int i=1;i<n;i++)
        {
            scanf("%d%d%d",&edges[i].u,&edges[i].v,&edges[i].w);
        }
        for (int i=1;i<=k;i++)
        {
            int t;
            scanf("%d",&t);
            boom[t]=true;
        }
        sort(edges+1,edges+n,cmp);
        long long ans=0;
        for (int i=1;i<n;i++)
        {
            int u=find_set(edges[i].u);
            int v=find_set(edges[i].v);
            int w=edges[i].w;
            if (boom[u]&&boom[v])
            {
                ans+=w;
            }
            else
            {
                unin(u,v);
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
