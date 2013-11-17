#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int OO=1e9+9;
const int maxn=222222;
const int INF=1e9+7;

struct hentai{
    int to;
    int next;
    int flow;
}edges[maxn];

struct death{
    int u;
    int v;
    int w;
}link[maxn];
int cnt;

int outque[maxn];
int head[maxn];
int edge;
int node,src;
int n,m;
int dis[maxn];
bool v[maxn];
int len;

queue<int>que;

void init(int _node,int _src)
{
    node=_node;
    src=_src;
    for (int i=0;i<=node;i++)
    {
        head[i]=-1;
        dis[i]=OO;
        v[i]=false;
    }
    edge=0;
    cnt=0;
}

void addedge(int u,int v,int w)
{
    edges[edge].flow=w;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].flow=w;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
    link[cnt].u=u;link[cnt].v=v;link[cnt].w=w;cnt++;
}


bool SPFA()
{
    int top;
    for (int i=0;i<=node;i++)
    {
        dis[i]=INF;
    }
    memset(v,0,sizeof(v));
    memset(outque,0,sizeof(outque));
    while (!que.empty()) que.pop();
    que.push(src);
    v[src]=true;
    dis[src]=0;
    while (!que.empty())
    {
        top=que.front();
        que.pop();
        v[top]=false;
        outque[top]++;
        if (outque[top]>node) return false;
        int k=head[top];
        while (k!=-1)
        {
            if ( dis[edges[k].to]==INF||dis[edges[k].to]>dis[top]+edges[k].flow )
            {
                dis[edges[k].to]=dis[top]+edges[k].flow;
                if (!v[edges[k].to])
                {
                    v[edges[k].to]=true;
                    que.push(edges[k].to);
                }
            }
            k=edges[k].next;
        }
    }
    return true;
}


int main()
{
    cin>>n>>m>>src;
    init(n,src);
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    cin>>len;

    //SPFA
    SPFA();

    int ans=0;
    for (int i=1;i<=node;i++)
    {
        if (dis[i]==len) ans++;
    }

    //(u,v)
    int u,v,w;
    for (int i=0;i<cnt;i++)
    {
        u=link[i].u;
        v=link[i].v;
        w=link[i].w;
        if ( (dis[u]<len) && (len-dis[u]<w) && (w-(len-dis[u])>len-dis[v]) ) ans++;
        if ( (dis[v]<len) && (len-dis[v]<w) && (w-(len-dis[v])>len-dis[u]) ) ans++;
        if ( (dis[v]<len) && (dis[u]<len) && (dis[u]+dis[v]+w==len*2) ) ans++;
    }
    //over

    cout<<ans<<endl;
    return 0;
}



/*
#include <iostream>
#include <cstring>

using namespace std;

const int OO=1e9+9;

struct hentai{
    int to;
    int next;
    int flow;
}edges[411111];

struct death{
    int u;
    int v;
    int w;
}link[411111];
int cnt;

int head[411111];
int edge;
int node,src;
int n,m;
int dis[411111];
bool v[411111];
int len;

void init(int _node,int _src)
{
    node=_node;
    src=_src;
    for (int i=0;i<=node;i++)
    {
        head[i]=-1;
        dis[i]=OO;
        v[i]=false;
    }
    edge=0;
    cnt=0;
}

void addedge(int u,int v,int w)
{
    edges[edge].flow=w;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].flow=w;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
    link[cnt].u=u;link[cnt].v=v;link[cnt].w=w;cnt++;
}

void dijkstra()
{
    int i,t;
    int mind;
    dis[src]=0;
    for (int loop=1;loop<=node;loop++)
    {
        mind=OO;
        for (i=1;i<=node;i++)
        {
            if (!v[i]&&dis[i]<mind)
            {
                mind=dis[i];
                t=i;
            }
        }
        v[t]=true;
        for (i=head[t];i!=-1;i=edges[i].next)
        {
            if (edges[i].flow+dis[t]<dis[edges[i].to])
            {
                dis[edges[i].to]=edges[i].flow+dis[t];
            }
        }
    }
}


int main()
{
    cin>>n>>m>>src;
    init(n,src);
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    cin>>len;
    //dijkstra
    dijkstra();
    int ans=0;
    for (int i=1;i<=node;i++)
    {
        if (dis[i]==len) ans++;
    }

    //(u,v)
    int u,v,w;
    for (int i=0;i<cnt;i++)
    {
        u=link[i].u;
        v=link[i].v;
        w=link[i].w;
        if ( (dis[u]<len) && (len-dis[u]<w) && (w-(len-dis[u])>len-dis[v]) ) ans++;
        if ( (dis[v]<len) && (len-dis[v]<w) && (w-(len-dis[v])>len-dis[u]) ) ans++;
        if ( (dis[v]<len) && (dis[u]+dis[v]+w==len*2) ) ans++;
    }
    //over

    cout<<ans<<endl;
    return 0;
}
*/

/*

    cout<<"step 1 ans="<<ans<<endl;
    int u,v,w;
    for (u=1;u<=node;u++)
    {
        if (dis[u]<len)
        {
            for (int i=head[u];i!=-1;i=edges[i].next)
            {
                v=edges[i].to;
                w=edges[i].flow;
                if (len-dis[u]<w&&w-(len-dis[u])<len-dis[v]) ans++;
            }
        }
    }
    cout<<"step 2 ans="<<ans<<endl;
    int tmp=0;
    for (u=1;u<=node;u++)
    {
        if (dis[u]<len)
        {
            for (int i=head[u];i!=-1;i=edges[i].next)
            {
                v=edges[i].to;
                w=edges[i].flow;
                if (dis[v]<len&&dis[u]+dis[v]+w==len*2) tmp++;
            }
        }
    }
    ans+=tmp/2;
    cout<<"step 3 ans="<<ans<<endl;

*/
