#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=311111;

struct EDGENODE{
    int to;
    int next;
}edges[maxn];

int head[maxn];
int edge;

void init_edge()
{
    memset(head,-1,sizeof(head));
    edge=0;
}

void addedge(int u,int v)
{
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}

int n;

struct TREENODE{
    int stu;
    int rank;
}tree[maxn];

bool flag;

void dfs(int u,int pa)
{
    int stu=0;
    int dub=0;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        int v=edges[i].to;
        if (v==pa) continue;
        dfs(v,u);
        dub=max(dub, stu&tree[v].stu);
        stu|=tree[v].stu;
    }
    int &p=tree[u].stu;
    p=1;
    while (p<=dub||(p&stu)) p<<=1;
    for (int i=(p<<1);i<(1<<26);i<<=1) if (i&stu) p|=i;
    for(int i=0;i<26;i++)
    {
        if((1<<i)&tree[u].stu)
        {
            tree[u].rank=26-i-1;
            if (tree[u].rank<0||tree[u].rank>=26) flag=true;
            break;
        }
    }
}

int main()
{
    while (cin>>n)
    {
        init_edge();
        memset(tree,0,sizeof(tree));
        flag=false;
        for (int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            addedge(a,b);
        }
        dfs(1,0);
        if (flag) cout<<"Impossible!";
        else
        for (int i=1;i<=n;i++)
        {
            cout<<char(tree[i].rank+'A')<<" ";
        }
        cout<<endl;
    }
    return 0;
}
/*

void dfs(int u,int pa)
{
    int stu=0;
    int dub=0;
    for (int i=head[u];i!=-1;i=edges[i].next)
    {
        int v=edges[i].to;
        if (v==pa) continue;
        dfs(v,u);
        if (stu&tree[v].stu) dub=max(dub, stu&tree[v].stu);
        stu|=tree[v].stu;
    }
    int &p=tree[u].stu;
    p=1;
    while (p<=dub||(p&stu)) p<<=1;
    for (int i=(p<<1);i<(1<<26);i<<=1) if (i&stu) p|=i;
    for(int i=0;i<26;i++)
    {
        if((1<<i)&tree[u].stu)
        {
            tree[u].rank=26-i-1;
            if (tree[u].rank<0||tree[u].rank>=26) flag=true;
            break;
        }
    }
}
*/
