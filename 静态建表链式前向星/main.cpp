#include <iostream>

using namespace std;

const int mm=111111;
const int OO=1e9;

int head[mm];
int work[mm];
int dis[mm];
int q[mm];

struct EdgeNode
{
    int to;
    int w;
    int next;
};

EdgeNode edge[mm];

int EG;

int node,src,dest;//节点数，源点，汇点

void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0;i<node;i++) head[i]=-1;
    EG=0;
}

void addedge(int u,int v,int c)
{
    edge[EG].to=v;edge[EG].w=c;edge[EG].next=head[u];head[u]=EG++;
    edge[EG].to=u;edge[EG].w=c;edge[EG].next=head[v];head[v]=EG++;
}

bool Dinic_bfs()
{
    int i,u,v,l,r=0;
    for (int i=0;i<node;i++) dis[i]=-1;
    dis[q[r++]=src]=0;
    for (l=0;l<r;l++)
    {
        for (i=head[u=q[l]];i>=0;i=edge[i].next)
        {
            if (edge[i].w&&dis[v=edge[i].to]<0)
            {

            }
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
