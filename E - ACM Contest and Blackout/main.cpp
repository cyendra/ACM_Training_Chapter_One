#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=211;
const int maxm=21111;
const double eps=1e-12;
const double OO=1e100;

struct Road{
    int u,v;
    int w;
    Road(){}
    Road(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Road& rhs) const{
        return w<rhs.w;
    }
};

class DisjointSet{
private:
    int pa[maxn];
    int n;
public:
    void makeSet(int n){
        this->n=n;
        for (int i=0;i<=n;i++) pa[i]=i;
    }
    int findSet(int x){
        if (x!=pa[x]) pa[x]=findSet(pa[x]);
        return pa[x];
    }
    void unionSet(int x,int y){
        x=findSet(x);
        y=findSet(y);
        if (x!=y) pa[x]=y;
    }
}disjointSet;

class Graph{
private:
    struct EdgeNode{
        int to;
        int w;
        int next;
    };
    int head[maxn],edge,n;
    EdgeNode edges[maxm*2];
    int maxCost[maxn][maxn];
    void dfsCost(int s,int u,int pa){
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            int w=edges[i].w;
            if (v==pa) continue;
            maxCost[s][v]=maxCost[s][u];
            if (maxCost[s][v]<w) maxCost[s][v]=w;
            dfsCost(s,v,u);
        }
    }
public:
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(int)*(n+1));
        edge=0;
    }
    void addedge(int u,int v,int w){
        edges[edge].w=w,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    void findMaxCost(){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                maxCost[i][j]=0;
        for (int i=1;i<=n;i++){
            dfsCost(i,i,-1);
        }
    }
    int getMaxCost(int x,int y){
        return maxCost[x][y];
    }
}tree;

vector<Road>road;

int n,m;
int minTree;
bool can[maxn][maxn];

void initializer(){
    memset(can,0,sizeof(can));
    disjointSet.makeSet(n);
    road.clear();
    minTree=0;
    tree.init(n);
}

void input(){
    for (int i=0;i<m;i++){
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        road.push_back(Road(a,b,w));
    }
}

void Kruskal(){
    sort(road.begin(),road.end());
    for (vector<Road>::iterator it=road.begin();it!=road.end();it++){
        int u=it->u;
        int v=it->v;
        int w=it->w;
        if (disjointSet.findSet(u)!=disjointSet.findSet(v)){
            minTree+=w;
            disjointSet.unionSet(u,v);
            tree.addedge(u,v,w);
            tree.addedge(v,u,w);
            can[u][v]=can[v][u]=true;
        }
    }
    tree.findMaxCost();
}
void solve(){
    int ans=INF;
    for (vector<Road>::iterator it=road.begin();it!=road.end();it++){
        int u=it->u;
        int v=it->v;
        int w=it->w;
        if (!can[u][v]){
            ans=min(ans,minTree-tree.getMaxCost(u,v)+w);
        }
    }
    printf("%d %d\n",minTree,ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        initializer();
        input();
        Kruskal();
        solve();
    }
    return 0;
}
