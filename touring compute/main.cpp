#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int maxn=55555;
const int INF=1e9;

struct XNODE
{
    int to;
    int w;
    int next;
}edges[maxn];

int n,m;
int C,A,B;

int edge,node,src;
long long distA[maxn];
long long distB[maxn];
long long distC[maxn];
int head[maxn];
bool visit[maxn];
int outque[maxn];

queue<int>que;

void prepare(int _node)
{
    node=_node;
    for (int i=0;i<=node;i++) head[i]=-1;
    edge=0;
}

void addedge(int u,int v,int c)
{
    edges[edge].w=c;edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
    edges[edge].w=c;edges[edge].to=u;edges[edge].next=head[v];head[v]=edge++;
}

bool SPFA(int src,long long *dist)
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
            if ( dist[edges[k].to]==INF||dist[edges[k].to]>dist[top]+edges[k].w )
            {
                dist[edges[k].to]=dist[top]+edges[k].w;
                if (!visit[edges[k].to])
                {
                    visit[edges[k].to]=true;
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
    int cnt=0;
    while (cin>>n>>m)
    {
        cnt++;
        cin>>C>>A>>B;
        prepare(n);
        for (int i=1;i<=m;i++)
        {
            int u,v,c;
            cin>>u>>v>>c;
            addedge(u,v,c);
        }
        SPFA(C,distC);
        SPFA(A,distA);
        SPFA(B,distB);
        long long ans=INF;
        for (int i=1;i<=n;i++)
        {
            ans=min( ans, distC[i]+distA[i]+distB[i] );
        }
        cout<<"Scenario #"<<cnt<<endl;
        if (ans==INF)
        {
            cout<<"Can not go reach!"<<endl;
        }
        else cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
