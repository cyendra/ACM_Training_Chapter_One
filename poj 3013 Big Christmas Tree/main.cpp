#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn=155555;
const int INF=-1;

struct NODE
{
    int to;
    long long w;
    int next;
}link[maxn];

int edge,node,src,dest;
long long dist[maxn];
int head[maxn];
bool visit[maxn];
int x[maxn];
int outque[maxn];

queue<int>que;

void prepare(int _node,int _src)
{
    node=_node;
    src=_src;
    for (int i=0;i<=node;i++) head[i]=-1;
    edge=0;
}

void addedge(int u,int v,int c)
{
    link[edge].w=c;link[edge].to=v;link[edge].next=head[u];head[u]=edge++;
    link[edge].w=c;link[edge].to=u;link[edge].next=head[v];head[v]=edge++;
}

bool SPFA()
{
    int top;
    for (int i=0;i<=node;i++)
    {
        dist[i]=INF;
    }
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    while (!que.empty()) que.pop();
    que.push(src);
    visit[src]=true;
    dist[src]=0;
    while (!que.empty())
    {
        top=que.front();
        que.pop();
        visit[top]=false;
        outque[top]++;
        if (outque[top]>node) return false;
        int k=head[top];
        while (k!=-1)
        {
            if ( dist[link[k].to]==INF||dist[link[k].to]>dist[top]+link[k].w )
            {
                dist[link[k].to]=dist[top]+link[k].w;
                if (!visit[link[k].to])
                {
                    visit[link[k].to]=true;
                    que.push(link[k].to);
                }
            }
            k=link[k].next;
        }
    }
    return true;
}

int main()
{
    int T,v,e;
    long long ans;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&v,&e);
        prepare(v,1);
        for (int i=1;i<=v;i++)
        {
            scanf("%d",&x[i]);
        }
        for (int i=1;i<=e;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        bool ret=SPFA();
        /*
        for (int i=1;i<=node;i++)
        {
            cout<<dist[i]<<endl;
        }
        */
        ans=0;
        for (int i=2;i<=node;i++)
        {
            if (dist[i]==INF)
            {
                ret=false;
                break;
            }
            ans+=dist[i]*x[i];
        }
        if (node==0||node==1){ret=true;ans=0;}
        if (ret) printf("%I64d\n",ans);
        else printf("No Answer\n");
    }
    return 0;
}
