#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
const int maxn=555;
const int maxm=2111111;
const int INF=0x3f3f3f3f;
const double OO=1e100;
const double eps=1e-8;
int dcmp(double a,double b){
    if (abs(a-b)<eps) return 0;
    if (a>b) return 1;
    return -1;
}
struct EdgeNode{
    int to;
    double w;
    int next;
};
struct HeapNode{
    double d;
    int u;
    HeapNode(){}
    HeapNode(double a,int b):d(a),u(b){}
    bool operator<(const HeapNode& rhs) const{
        return dcmp(d,rhs.d)>0;
    }
};
struct Prim{
    EdgeNode edges[maxm];
    int head[maxn];
    int edge,n;
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v,double c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    double dis[maxn];
    int pre[maxn];
    void prim(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<=n;i++) dis[i]=OO;
        dis[s]=0;
        memset(done,0,sizeof(done));
        que.push(HeapNode(0,s));
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            done[u]=true;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                double w=edges[i].w;
                if (done[v]) continue;
                if (dcmp(dis[v],w)>0 ){
                    dis[v]=w;
                    pre[v]=u;
                    que.push(HeapNode(dis[v],v));
                }
            }
        }
    }
}tree;
int S,P,n;
struct City{
    double x;
    double y;
    double disTo(City& r){
        return sqrt( (x-r.x)*(x-r.x)+(y-r.y)*(y-r.y) );
    }
};
City city[maxn];
vector<double>road;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&S,&P);
        n=P;
        tree.init(n);
        for (int i=1;i<=n;i++){
            scanf("%lf%lf",&city[i].x,&city[i].y);
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (i==j) continue;
                tree.addedge(i,j,city[i].disTo(city[j]));
            }
        }
        tree.prim(1);
        road.clear();
        for (int i=2;i<=n;i++){
            road.push_back( tree.dis[i] );
        }
        sort(road.begin(),road.end(),greater<double>());
        printf("%0.2f\n",road[S-1]);
    }
    return 0;
}
