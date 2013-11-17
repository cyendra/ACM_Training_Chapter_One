#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define PR pair<int,int>

using namespace std;

//const
const int maxn=1111;
const int maxm=11111;

//Tree
struct EDGENODE{
    int to;
    int next;
}edges[maxm];
int edge;
int head[maxn];
void addedge(int u,int v){
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
}
void init(){
    memset(head,-1,sizeof(head));
    edge=0;
}

//------
int n,m;
bool vis[maxn][2];
PR f[maxn][2];

//dfs()
PR dfs(int x,int y,int pa)
{
    if (vis[x][y]) return f[x][y];
    PR ret=make_pair(0,0),ret0=make_pair(0,0),tmp;
    //----∑≈÷√
    ret.first+=1;
    for (int k=head[x];k!=-1;k=edges[k].next)
    {
        int v=edges[k].to;
        if (v!=pa)
        {
            tmp=dfs(v,1,x);
            ret.first+=tmp.first;
            ret.second+=tmp.second;
        }
    }
    if (y==0&&pa!=-1) ret.second+=1;
    //----≤ª∑≈÷√
    if (y==1||pa==-1)
    {
        for (int k=head[x];k!=-1;k=edges[k].next)
        {
            int v=edges[k].to;
            if (v!=pa)
            {
                tmp=dfs(v,0,x);
                ret0.first+=tmp.first;
                ret0.second+=tmp.second;
            }
        }
        if (pa!=-1) ret0.second+=1;
        ret=min(ret,ret0);
    }
    //----
    vis[x][y]=true;
    f[x][y]=ret;
    return ret;
}

int main()
{
    int T;
    PR tmp,ans;
    scanf("%d",&T);
    while (T--)
    {
        init();
        memset(f,0,sizeof(f));
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        ans=make_pair(0,0);
        for (int i=0;i<n;i++)
        {
            if (!vis[i][0])
            {
                tmp=dfs(i,0,-1);
                ans.first+=tmp.first;
                ans.second+=tmp.second;
            }
        }
        printf("%d %d %d\n",ans.first,m-ans.second,ans.second);
    }
    return 0;
}
