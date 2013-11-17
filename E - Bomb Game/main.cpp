#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cmath>
#include <time.h>
using namespace std;
/*
int main(){
    int T=10;
    srand((int)time(0));
    printf("%d\n",T);
    while (T--){
        int m=rand()%50+3;
        printf("%d\n",m);
        while (m--){
            int x=rand()%200-100;
            int y=rand()%200-100;
            printf("%d %d\n",x,y);
        }
    }

}
*/
const int maxn=11111;
const int maxm=2111111;
const double eps=1e-4;

struct EDGENODE{
    int to;
    int next;
};
struct TWO_SAT{
    int head[maxn*2];
    EDGENODE edges[maxm*2];
    int edge;
    int n;
    void init(int n){
        this->n=2*n;
        memset(head,-1,sizeof(head));
        edge=0;
    }
    void addedge(int u,int v){
        edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    // x = xval or y = yval
    void add_clause(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x^1,y);
        addedge(y^1,x);
    }
    //x=xval
    void add_con(int x,int xval){
        x=x*2+xval;
        addedge(x^1,x);
    }
    //
    void add_self(int x,int xval,int y,int yval){
        x=x*2+xval;
        y=y*2+yval;
        addedge(x,y);
    }
    int pre[maxn],lowlink[maxn],sccno[maxn],scc_cnt,dfs_clock;
    stack<int>stk;
    void dfs(int u)
    {
        pre[u]=lowlink[u]=++dfs_clock;
        stk.push(u);
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (!pre[v]){
                dfs(v);
                lowlink[u]=min(lowlink[u],lowlink[v]);
            } else if (!sccno[v]){
                lowlink[u]=min(lowlink[u],pre[v]);
            }
        }
        if (lowlink[u]==pre[u]){
            scc_cnt++;
            int x;
            do{
                x=stk.top();
                stk.pop();
                sccno[x]=scc_cnt;
            }while (x!=u);
        }
    }
    void find_scc(int n)
    {
        dfs_clock=scc_cnt=0;
        memset(sccno,0,sizeof(sccno));
        memset(pre,0,sizeof(pre));
        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++) if (!pre[i]) dfs(i);
    }
    bool solve(){
        find_scc(n);
        for (int i=0;i<n;i+=2){
            if (sccno[i]==sccno[i^1]) return false;
        }
        return true;
    }
}TwoSAT;

struct point{
    double x,y;
    void input(){
        scanf("%lf%lf",&x,&y);
    }
};

struct gamer{
    point p[2];
    void input(){
        p[0].input();
        p[1].input();
    }
}a[maxn];

int n;

bool kill(point i,point j,double r){
    bool res;
    double d;
    d=( i.x-j.x )*( i.x-j.x ) + ( i.y-j.y )*( i.y-j.y );
    if ( r*r > d ) res=true;
    else res=false;
    return res;

}

bool C(double x){
    TwoSAT.init(n);
    for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){ // p-0 q-1
        for (int k=0;k<2;k++){
        for (int g=0;g<2;g++){
            if ( kill(a[i].p[k],a[j].p[g],x) ){
                TwoSAT.add_clause(i,k^1,j,g^1);
            }
        }}
    }}
    bool res=TwoSAT.solve();
    return res;
}

int main()
{
    while (~scanf("%d",&n)){
        for (int i=0;i<n;i++){
            a[i].input();
        }
        double l=0.0,r=10000.0;
        double mid=0;
        while (fabs(r-l)>eps){
            mid=(l+r)/2;
            if (C(mid)){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        printf("%0.2f\n",mid/2);
    }
    return 0;
}
*/
