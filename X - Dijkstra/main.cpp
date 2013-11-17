#include <iostream>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define max_int       INT_MAX / 2
#define max_long      0xFFFFFFFFFFFFFFFLL / 2
#define two(a)        (1 << (a))
#define eps           1e-6
#define FF(i, a, b)   for (int i = (a); i <= (b); i++)
#define FFD(i, a, b)  for (int i = (a); i >= (b); i--)

const int OO=1e16;
const int INF=1e9;
const int maxn=111111;

struct EDGE
{
    int to;
    int w;
    int next;
} edges[maxn*2];

int edge;
int head[maxn];
long long dist[maxn];
int pre[maxn];
int road[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].w=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].w=c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

void dijkstra(int n,long long dist[],EDGE edges[],int pre[],int src,int dest)
{
    int u,v,w;
    long long _min;
    bool visit[maxn]={0};
    for (int i=1;i<=n;i++)
    {
        dist[i]=OO;
    }
    dist[src]=0;
    for (int loop=1; loop<=n; loop++)
    {
        u=0;
        _min=OO;
        for (int i=1; i<=n; i++)
        {
            if (!visit[i]&&dist[i]<_min)
            {
                _min=dist[i];
                u=i;
            }
        }
        if (u==0) return;
        visit[u]=true;
        if (u==dest) return;
        for (int i=head[u];i!=-1;i=edges[i].next)
        {
            v=edges[i].to;
            w=edges[i].w;
            if (!visit[v]&&dist[u]+w<dist[v])
            {
                dist[v]=dist[u]+w;
                pre[v]=u;
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    FF(i ,1, m)
    {
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        addedge(u,v,c);
    }
    //SPFA(n,1,n,dist,pre);
    dijkstra(n,dist,edges,pre,1,n);

    if (dist[n]==OO)
    {
        printf("-1\n");
    }
    else
    {
        int r=0;
        int p=n;
        while (p!=0)
        {
            road[r++]=p;
            p=pre[p];
        }
        for (int i=r-1; i>=0; i--)
        {
            printf("%d ",road[i]);
        }
        printf("\n");
    }
    return 0;
}


/*
bool SPFA(int node, int src, int dest, int dist[], int pre[])
{
    //queue<int>que;
    int queue[maxn];
    int iq,i;
    bool visit[maxn];
    int outque[maxn*100];
    int top;
    for (int i=0;i<=node;i++)
    {
        dist[i]=INF;
    }
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    memset(pre,0,sizeof(pre));
    //while (!que.empty()) que.pop();
    iq=0;
    //que.push(src);
    queue[iq++]=src;
    visit[src]=true;
    dist[src]=0;
    i=0;
    //while (!que.empty())
    while (i!=iq)
    {
        //top=que.front();
        top=queue[i];
        //que.pop();
        visit[top]=false;
        outque[top]++;
        if (outque[top]>node) return false;
        int k=head[top];
        while (k!=-1)
        {
            if ( dist[edges[k].to]==INF||dist[edges[k].to]>dist[top]+edges[k].w )
            {
                dist[edges[k].to]=dist[top]+edges[k].w;
                pre[edges[k].to]=top;
                if (!visit[edges[k].to])
                {
                    visit[edges[k].to]=true;
                    //que.push(edges[k].to);
                    queue[iq]=edges[k].to;
                    iq++;
                }
            }
            k=edges[k].next;
        }
        i++;
    }
    return true;
}
*/
void dfs(int p)
{
    if (p==1)
    {
        printf("1");
        return;
    }
    dfs(pre[p]);
    printf(" %d",p);
}









