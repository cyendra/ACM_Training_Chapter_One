#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn=1111;
const int maxm=4111111;
int n,m;

struct EDGENODE{
    int to;
    int w;
    bool cut;
    bool nocut;
    int next;
};

struct EDGE{
    int u,v;
    int w;
};
EDGE grid[maxm];
bool eql(EDGE a,EDGE b){
    if (a.u==b.u&&a.v==b.v) return true;
    return false;
}
int plz;
bool cmp(EDGE a,EDGE b){
    if (a.u==b.u){
        return a.v<b.v;
    }
    return a.u<b.u;
}

struct BCC_GRAPH{
    int head[maxn];
    EDGENODE edges[maxm];
    int edge;
    void init(){
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v,int c,bool no){
        edges[edge].nocut=no,edges[edge].cut=0,edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    //BCC_Tarjan
    int dfn[maxn],low[maxn],dfs_clock;
    int dfs(int u,int fa){
        int lowu=dfn[u]=++dfs_clock;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==fa) continue;
            if (!dfn[v]){
                int lowv=dfs(v,u);
                lowu=min(lowu,lowv);
                if (dfn[u]<lowv){//cut ге
                    edges[i].cut=true;
                    edges[i^1].cut=true;
                }
            }
            else if (dfn[v]<dfn[u]){
                lowu=min(lowu,dfn[v]);
            }
        }
        low[u]=lowu;
        return lowu;
    }
    void find_bcc(int n){
        memset(dfn,0,sizeof(dfn));
        dfs_clock=0;
        for (int i=1;i<=n;i++){
            if (!dfn[i]) dfs(i,-1);
        }
    }
    bool vis[maxn];
    void blu(int u){
        vis[u]=true;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!vis[v]) blu(v);
        }
    }
    bool isok(){
        memset(vis,0,sizeof(vis));
        blu(1);
        for (int i=1;i<=n;i++){
            if (!vis[i]) return false;
        }
        return true;
    }
}solver;

int main()
{
    while (~scanf("%d%d",&n,&m)){
        if (n==0&&m==0) break;
        solver.init();
        plz=0;
        while (m--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if (x>y) swap(x,y);
            grid[plz].u=x;
            grid[plz].v=y;
            grid[plz].w=z;
            plz++;
        }
        sort(grid,grid+plz,cmp);
        for (int i=0;i<plz;i++){
            int x=grid[i].u;
            int y=grid[i].v;
            int z=grid[i].w;
            if (i+1<plz&&eql(grid[i],grid[i+1])){
                solver.addedge(x,y,z,1);
                solver.addedge(y,x,z,1);
                //cerr<<x<<" "<<y<<" "<<z<<" 1"<<endl;
                while (i+1<plz&&eql(grid[i],grid[i+1])) i++;
            }
            else{
                solver.addedge(x,y,z,0);
                solver.addedge(y,x,z,0);
                //cerr<<x<<" "<<y<<" "<<z<<" 0"<<endl;
            }
        }

        if (!solver.isok()){
            printf("0\n");
            continue;
        }
        //cerr<<"wtf?"<<endl;
        solver.find_bcc(n);
        int ans=-1;
        for (int i=0;i<solver.edge;i++){
            if (solver.edges[i].cut&&!solver.edges[i].nocut){
                if (ans==-1||solver.edges[i].w<ans){
                    ans=solver.edges[i].w;
                }
            }
        }
        if (ans==0) ans=1;
        printf("%d\n",ans);
    }
    return 0;
}
