#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int INF=0x3f3f3f3f;
const int maxn=1111;
const int maxm=1111;
const double eps=1e-12;
const double OO=1e100;

int dcmp(double x,double y){
    if (abs(x-y)<eps) return 0;
    if (x<y) return -1;
    else return 1;
}
struct Road{
    int u,v;
    double w;
    Road(){}
    Road(int u,int v,double w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
    bool operator<(const Road& rhs) const{
        return dcmp(w,rhs.w)<0;
    }
};
struct Point{
    double x,y;
    double pop;
    Point(){}
    Point(double x,double y,double pop){
        this->x=x;
        this->y=y;
        this->pop=pop;
    }
    double disToPot(Point& p){
        return sqrt( (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y) );
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
        double w;
        int next;
    };
    int head[maxn],edge,n;
    EdgeNode edges[maxm*2];
    double maxCost[maxn][maxn];
    void dfsCost(int s,int u,int pa){
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            double w=edges[i].w;
            if (v==pa) continue;
            maxCost[s][v]=maxCost[s][u];
            if (maxCost[s][v]<w) maxCost[s][v]=w;
            dfsCost(s,v,u);
        }
    }
    //debug
    void dfsBase(int u,int pa){
        printf("pa( %d ) --> u( %d )\n",pa,u);
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (v==pa) continue;
            dfsBase(v,u);
        }
    }
public:
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(int)*(n+1));
        edge=0;
    }
    void addedge(int u,int v,double w){
        edges[edge].w=w,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    void findMaxCost(){
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                maxCost[i][j]=0;
        for (int i=0;i<n;i++){
            dfsCost(i,i,-1);
        }
    }
    double getMaxCost(int x,int y){
        return maxCost[x][y];
    }
    //debug
    void showGraph(){
        cerr<<"Graph:"<<endl;
        dfsBase(0,-1);
        cerr<<"Graph over"<<endl;
    }
    void showMaxCost(){
        cerr<<"MaxCost:"<<endl;
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cerr<<getMaxCost(i,j)<<" ";
            }
            cerr<<endl;
        }
        cerr<<"MaxCost over"<<endl;
    }
}tree;

vector<Road>road;
vector<Point>city;

int n;
double minTree;

void initializer(){
    disjointSet.makeSet(n);
    road.clear();
    city.clear();
    minTree=0;
    tree.init(n);
}

void input(){
    for (int i=0;i<n;i++){
        double a,b,w;
        scanf("%lf%lf%lf",&a,&b,&w);
        city.push_back(Point(a,b,w));
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            double d=city[i].disToPot(city[j]);
            road.push_back(Road(i,j,d));
        }
    }
}
void Kruskal(){
    sort(road.begin(),road.end());
    for (vector<Road>::iterator it=road.begin();it!=road.end();it++){
        int u=it->u;
        int v=it->v;
        double w=it->w;
        if (disjointSet.findSet(u)!=disjointSet.findSet(v)){
            minTree+=w;
            disjointSet.unionSet(u,v);
            tree.addedge(u,v,w);
            tree.addedge(v,u,w);
        }
    }
    tree.findMaxCost();
    //debug
    //tree.showGraph();
    //tree.showMaxCost();
}
void solve(){
    double ans=0;
    for (vector<Road>::iterator it=road.begin();it!=road.end();it++){
        int u=it->u;
        int v=it->v;
        double A=city[u].pop+city[v].pop;
        double B=minTree-tree.getMaxCost(u,v);
        double res=A/B;
        if (res>ans) ans=res;
    }
    printf("%0.2f\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        initializer();
        input();
        Kruskal();
        solve();
    }
    return 0;
}

