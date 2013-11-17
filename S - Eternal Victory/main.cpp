#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF=1e9+9;
const int maxn=111111;

int n;
long long ans;

struct EDGE{
    int to;
    int w;
    int next;
}edges[maxn*2];

int edge;
int head[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    memset(edges,0,sizeof(edges));
    edge=0;
    ans=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].w=c;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].w=c;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

long long dfs(int u,int dad,long long flow)
{
    long long ret=flow;
    int v,w;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        v=edges[i].to;
        w=edges[i].w;
        if (v!=dad)
        {
            ret=max( ret, dfs(v,u,flow+w) );
        }
    }
    return ret;
}

int main()
{
    int n;
    cin>>n;
    init();
    for (int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        ans+=w*2;
    }
    long long ret=dfs(1,0,0);
    cout<<ans-ret<<endl;
    return 0;
}
