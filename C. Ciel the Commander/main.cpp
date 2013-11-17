#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=311111;

struct TREENODE{
    bool visit;
    int rank;
}tree[maxn];
int sz[maxn];
struct EDGENODE{
    int to;
    int next;
}edges[maxn];
int head[maxn];
int edge;
void init_edge(){
    memset(head,-1,sizeof(head));
    edge=0;
}
void addedge(int u,int v){
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}

void dfs(int u,int pa);
int find_center(int x);
void solve(int x,int rk);

int n;

void dfs(int u,int pa)
{
    sz[u]=1;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        int v=edges[i].to;
        if (v!=pa&&!tree[v].visit)
        {
            dfs(v,u);
            sz[u]+=sz[v];
        }
    }
}

int find_center(int x)
{
    int p=0;
    dfs(x,p);
    int cap=sz[x]/2;
    bool found=true;
    while (found)
    {
        found=false;
        for (int i=head[x];i!=-1;i=edges[i].next)
        {
            int y=edges[i].to;
            if (!tree[y].visit&&y!=p&&sz[y]>cap)
            {
                found=true;
                p=x;
                x=y;
                break;
            }
        }
    }
    return x;
}

void solve(int x,int rk)
{
    int u=find_center(x);
    tree[u].rank=rk;
    tree[u].visit=true;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        int v=edges[i].to;
        if (!tree[v].visit) solve(v,rk+1);
    }
}

int main()
{
    while (cin>>n)
    {
        init_edge();
        memset(tree,0,sizeof(tree));
        for (int i=0; i<n-1; i++)
        {
            int a,b;
            cin>>a>>b;
            addedge(a,b);
        }
        solve(1,0);
        for (int i=1; i<=n; i++)
        {
            cout<<char(tree[i].rank+'A')<<" ";
        }
        cout<<endl;
    }
    return 0;
}
