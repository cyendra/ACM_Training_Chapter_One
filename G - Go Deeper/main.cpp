#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

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
int n,m;
int a[maxn];
int b[maxn];
int c[maxn];

bool C(int x){
    TwoSAT.init(n);
    for (int i=1;i<=x;i++){
        if (c[i]==0){
            TwoSAT.add_clause(a[i],1,b[i],1);
        }
        else if (c[i]==1){
            TwoSAT.add_clause(a[i],1,b[i],0);
            TwoSAT.add_clause(a[i],0,b[i],1);
        }
        else if (c[i]==2){
            TwoSAT.add_clause(a[i],0,b[i],0);
        }
    }
    return TwoSAT.solve();
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        int l=0,r=m;
        int ans=0;
        while (l<=r){
            int mid=l+(r-l)/2;
            if (C(mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
