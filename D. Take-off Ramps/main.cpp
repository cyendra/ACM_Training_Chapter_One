#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
typedef long long LL;
const long long INF=1LL << 60;
const int maxn=500000;
const int maxm=5000000;
struct EdgeNode{
    int to;
    LL w;
    int next;
};/*==============================================*\
 | Dijkstra+堆优化
 | INIT: init(n);addedge(u,v,c);节点编号0~n
 | CALL: dijkstra(int s);dis[]:最短路;pre[]:前驱
\*==============================================*/
struct HeapNode{
    LL d;
    int u;
    HeapNode(){}
    HeapNode(LL a,int b):d(a),u(b){}
    bool operator<(const HeapNode& rhs) const{
        return d>rhs.d;
    }
};
struct Dijkstra{
    EdgeNode edges[maxm];
    int head[maxn];
    int edge,n;
    void init(int n){
        this->n=n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v,LL c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    bool done[maxn];
    LL dis[maxn];
    int pre[maxn];
    void dijkstra(int s){
        priority_queue<HeapNode>que;
        for (int i=0;i<=n;i++) dis[i]=INF;
        dis[s]=0;
        memset(done,0,sizeof(done));
        que.push(HeapNode(0,s));
        while (!que.empty()){
            HeapNode x=que.top();
            que.pop();
            int u=x.u;
            if (done[u]) continue;
            done[u]=true;
            for (int i=head[u];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                LL w=edges[i].w;
                if (dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    pre[v]=u;
                    que.push(HeapNode(dis[v],v));
                }
            }
        }
    }
}G;
struct Data{
    int x,d,t,p;
    int id;
}a[maxn];
struct POI{
    int p;
    int id;
    POI(){}
    POI(int a,int b):p(a),id(b){}
};
vector<POI>vec;
bool cmp(POI a,POI b){
    return a.p<b.p;
}
vector<int>ans;
int mp[maxn];
int main()
{
    int n,L,m;
    memset(mp,-1,sizeof(mp));
    scanf("%d%d",&n,&L);
    G.init(2*n+1);
    m=0;
    for (int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i].x,&a[i].d,&a[i].t,&a[i].p);
        a[i].id=i;
        G.addedge(i,i+n,a[i].p+a[i].t);
        if (a[i].t<a[i].d){
            mp[i+n]=i;
        }
        //cerr<<i<<" "<<i+n<<" "<<a[i].t<<endl;
        vec.push_back(POI(a[i].x-a[i].p,i));
        vec.push_back(POI(a[i].x+a[i].d,i+n));
    }
    vec.push_back(POI(L,2*n+1));
    vec.push_back(POI(0,0));
    sort(vec.begin(),vec.end(),cmp);
    for (int i=0;i<(int)vec.size()-1;i++){
        if (vec[i].p<0) continue;
        G.addedge(vec[i].id,vec[i+1].id,abs(vec[i+1].p-vec[i].p));
        G.addedge(vec[i+1].id,vec[i].id,abs(vec[i].p-vec[i+1].p));
        //cerr<<vec[i].id<<" "<<vec[i+1].id<<" "<<abs(vec[i+1].p-vec[i].p)<<endl;
    }
    G.dijkstra(0);
    printf("%I64d\n",G.dis[2*n+1]);
    int t=2*n+1;
    while (t!=0){
        if (mp[t]==G.pre[t]) ans.push_back(G.pre[t]);
        t=G.pre[t];
    }
    printf("%d\n",ans.size());
    for (int i=(int)ans.size()-1;i>=0;i--){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}

