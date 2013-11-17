#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

const int maxn=50000;
const long long INF=1e16;

struct NODE
{
    int to;
    int w;
    int next;
} link[maxn];

struct inp
{
    string s;
    int d;
} car[maxn];

int edge,node,src,dest;
long long dist[maxn];
int head[maxn];
bool visit[maxn];
int outque[maxn];

queue<int>que;

void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<=node; i++) head[i]=-1;
    //for (int i=0;i<=node;i++) soft[i]=-1;
    edge=0;
    //softedge=0;
}

void addedge(int u,int v,int c)
{
    link[edge].w=c;
    link[edge].to=v;
    link[edge].next=head[u];
    head[u]=edge++;
    //cout<<head[u]<<" "<<u<<endl;
    //link[edge].w=c;link[edge].to=u;link[edge].next=head[v];head[v]=edge++;
}

bool SPFA()
{
    int top;
    for (int i=0; i<=node; i++)
    {
        dist[i]=INF;
    }
    memset(visit,0,sizeof(visit));
    memset(outque,0,sizeof(outque));
    while (!que.empty()) que.pop();
    que.push(src);
    visit[src]=true;
    dist[src]=0;
    //cout<<"spfabegin"<<endl;
    //int tin=0;
    while (!que.empty())
    {
        //cout<<"stk"<<tin++<<endl;
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
    long long ans1,ans2;
    int d1,d2;
    int bg,ed;
    int Q,n,t;
    cin>>Q;
    while (Q--)
    {
        cin>>n>>t;
        for (int i=0; i<t; i++)
        {
            cin>>car[i].s>>car[i].d;
        }
        cin>>d1>>d2;
        cin>>bg>>ed;

        prepare(n,bg,ed);
        for (int i=0; i<t; i++)
        {
            int len=car[i].s.length();
            int last=0;
            for (int j=0; j<len; j++)
            {
                int u=car[i].s[j-2]-'0';
                int v=car[i].s[j]-'0';
                addedge(u,v,1);
            }
        }
        SPFA();
        ans1=dist[dest]*d1;
        if (dist[dest]==INF) ans1=INF;
        memset(dist,0,sizeof(dist));
        memset(head,-1,sizeof(head));
        prepare(n,bg,ed);

        for (int i=0; i<t; i++)
        {
            //cout<<i<<"=i d="<<car[i].d<<endl;
            if ( car[i].d==1 )
            {
                int len=car[i].s.length();
                for (int j=2; j<len; j+=2)
                {
                    int u=car[i].s[j-2]-'0';
                    int v=car[i].s[j]-'0';
                    addedge(u,v,1);
                }
            }
        }
        SPFA();
        ans2=dist[dest]*d2;
        if (dist[dest]==INF) ans2=INF;
        long long ans=INF;
        ans=min(ans1,ans2);
        if (ans==INF) ans=-1;
        cout<<ans<<endl;
        //cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
