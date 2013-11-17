#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


const int OO=1e9;
const int INF=1e9;
const int maxn=51111;
const int max_prime=4000009;

struct NODE{
    int num;
    int max_num;
    bool visit;
    bool prime;
}tree[maxn];

struct EDGE{
    int to;
    int next;
}edges[2*maxn];

int head[maxn];
int n,edge;
int ans;

void init()
{
    memset(head,-1,sizeof(head));
    memset(edges,0,sizeof(edges));
    memset(tree,0,sizeof(tree));
    edge=0;
    ans=0;
}

void addedge(int u,int v)
{
    edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

bool not_prime[max_prime];
void find_prime()
{
    memset(not_prime,0,sizeof(not_prime));
    not_prime[0]=true;
    not_prime[1]=true;
    for (int i=2;i*i<max_prime;i++)
    {
        if (!not_prime[i])
        {
            for (int j=i+i;j<max_prime;j+=i)
            {
                not_prime[j]=true;
            }
        }
    }
}

void dfs(int u)
{
    int v;
    bool ok=tree[u].prime;
    tree[u].visit=true;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].to;
        if (!tree[v].visit)
        {
            dfs(v);
            if (!tree[v].prime)
            {
                tree[u].prime=false;
                ok=false;
            }
            if (tree[v].max_num>=tree[u].num)
            {
                ok=false;
            }
            if (tree[v].max_num>=tree[u].max_num)
            {
                tree[u].max_num=tree[v].max_num;
            }
        }
    }
    if (ok) ans++;
}

int main()
{
    find_prime();
    while (scanf("%d",&n)!=EOF)
    {
        init();
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&tree[i].num);
            if ( !not_prime[tree[i].num] )
            {
                tree[i].prime=true;
            }
            else
            {
                tree[i].prime=false;
            }
            tree[i].visit=false;
            tree[i].max_num=tree[i].num;
        }
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        dfs(1);
        printf("%d\n\n",ans);
    }
    return 0;
}











