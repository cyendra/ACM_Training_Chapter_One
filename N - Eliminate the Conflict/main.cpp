#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn=71111;
const int maxm=8111111;
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
int b;
int main()
{
    int T;
    int cas=0;
    scanf("%d",&T);
    while (T--){
        cas++;
        scanf("%d%d",&n,&m);
        TwoSAT.init(n*3);
        // 0-石头 1-布 2-剪子
        for (int i=0;i<n;i++){
            TwoSAT.add_clause(i*3+0,0,i*3+1,0);
            TwoSAT.add_clause(i*3+0,0,i*3+2,0);

            TwoSAT.add_clause(i*3+1,0,i*3+0,0);
            TwoSAT.add_clause(i*3+1,0,i*3+2,0);

            TwoSAT.add_clause(i*3+2,0,i*3+0,0);
            TwoSAT.add_clause(i*3+2,0,i*3+1,0);
        }
        for (int i=0;i<n;i++){
            int b;
            scanf("%d",&b);
            if (b==1){//石头
                TwoSAT.add_clause(i*3+0,1,i*3+1,1);//石头or布
                TwoSAT.add_con(i*3+2,0);//no 剪子
            }
            if (b==2){//布
                TwoSAT.add_clause(i*3+1,1,i*3+2,1);//布or剪子
                TwoSAT.add_con(i*3+0,0);//no 石头
            }
            if (b==3){//剪子
                TwoSAT.add_clause(i*3+2,1,i*3+0,1);//剪子or石头
                TwoSAT.add_con(i*3+1,0);//no 布
            }
        }
        for (int i=1;i<=m;i++){
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            x--;
            y--;
            if (t==0){
                TwoSAT.add_clause(x*3+0,0,y*3+0,1);
                TwoSAT.add_clause(y*3+0,0,x*3+0,1);
                TwoSAT.add_clause(x*3+1,0,y*3+1,1);
                TwoSAT.add_clause(y*3+1,0,x*3+1,1);
                TwoSAT.add_clause(x*3+2,0,y*3+2,1);
                TwoSAT.add_clause(y*3+2,0,x*3+2,1);
            }
            if (t==1){
                TwoSAT.add_clause(x*3+0,0,y*3+0,0);
                TwoSAT.add_clause(x*3+1,0,y*3+1,0);
                TwoSAT.add_clause(x*3+2,0,y*3+2,0);
            }
        }
        bool res=TwoSAT.solve();
        if (res) printf("Case #%d: yes\n",cas);
        else printf("Case #%d: no\n",cas);
    }
    return 0;
}
