#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn=1111;
const int maxm=11111;
const int INF=0x3f3f3f3f;

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

struct Edge{
    int u,v;
    int w;
    Edge(){}
    Edge(int u,int v,int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Edge& rhs) const{
        return w<rhs.w;
    }
};
int n,m;
Edge vec[maxm];

int Kruskal(int s){
    int minCost=INF;
    int maxCost=-1;
    int cnt=0;
    disjointSet.makeSet(n);
    for (int i=s;i<m;i++){
        int u=vec[i].u;
        int v=vec[i].v;
        int w=vec[i].w;
        if (disjointSet.findSet(u)!=disjointSet.findSet(v)){
            disjointSet.unionSet(u,v);
            cnt++;
            minCost=min(minCost,w);
            maxCost=max(maxCost,w);
        }
    }
    if (cnt!=n-1) return INF;
    if (cnt==1) return 0;
    return maxCost-minCost;
}

int main()
{
    while (~scanf("%d%d",&n,&m)){
        if (n==0&&m==0) break;
        for (int i=0;i<m;i++){
            scanf("%d%d%d",&vec[i].u,&vec[i].v,&vec[i].w);
        }
        sort(vec,vec+m);
        int ans=INF;
        for (int i=0;i<m;i++){
            ans=min(ans,Kruskal(i));
        }
        if (ans==INF) printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
