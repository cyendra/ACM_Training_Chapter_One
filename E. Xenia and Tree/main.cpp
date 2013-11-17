#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
const int maxn=211111;
const int maxm=611111;
const int INF=0x3f3f3f;
//------最短路----------
struct EdgeNode{
    int to;
    int next;
};
EdgeNode edges[maxm];
int head[maxn],edge,n;
void addedge(int u,int v){
    edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
}
void init(){
    memset(head,-1,sizeof(head));
    edge=0;
}

//---------MAIN---------------
bool vis[maxn];
int dis[maxn];
queue<int>que;
int block;
void dfs(int u,int pa){
    if (pa==0) dis[u]=0;
    else dis[u]=dis[pa]+1;
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        if (v!=pa) dfs(v,u);
    }
}
void bfs(){
    memset(vis,0,sizeof(vis));
    while (!que.empty()){
        int u=que.front();
        que.pop();
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                if (!vis[v]){
                    que.push(v);
                    vis[v]=true;
                }
            }
        }
    }
}
//-----RMQ--------------
int d[maxn][30];
//元素从1编号到n
void makeRmqIndex(int A[],int n){
    for(int i=1;i<=n;i++) d[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            d[i][j] = A[d[i][j-1]] < A[d[i+(1<<(j-1))][j-1]]? d[i][j-1]:d[i+(1<<(j-1))][j-1];
}
int rmqIndex(int L,int R,int A[]){
    int k=0;
    while ((1<<(k+1))<=R-L+1) k++;
    return A[d[L][k]]<A[d[R-(1<<k)+1][k]]? d[L][k]:d[R-(1<<k)+1][k];
}
//------LCA------------------------
int deep[maxn];
int E[maxn*2],R[maxn],D[maxn*2],mn;
void dfs(int u,int p,int d){
    E[++mn]=u;
    D[mn]=d;
    R[u]=mn;
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        if (v==p) continue;
        dfs(v,u,d+1);
        E[++mn]=u;
        D[mn]=d;
    }
}
void getd(int u,int p,int w){
    deep[u]=w;
    for (int i=head[u];i!=-1;i=edges[i].next){
        int v=edges[i].to;
        if (v==p) continue;
        getd(v,u,w+1);
    }
}
void LCA_init(){
    mn=0;
    memset(R,0,sizeof(R));
    dfs(1,-1,1);
    makeRmqIndex(D,mn);
    getd(1,-1,0);
}
int LCA(int u,int v){
    if (R[u]>=R[v]) return E[rmqIndex(R[v],R[u],D)];
    else return E[rmqIndex(R[u],R[v],D)];
}
int getDis(int u,int v){
    int lca=LCA(u,v);
    return deep[u]+deep[v]-deep[lca]*2;
}

int main()
{
    int m;
    int x,y;
    scanf("%d%d",&n,&m);
    init();
    block=sqrt(m);
    for (int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(1,0);
    LCA_init();
    for (int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        if (x==1){
            que.push(y);
            dis[y]=0;
        }
        else if (x==2){
            if ((int)que.size()>block){
                bfs();
                printf("%d\n",dis[y]);
            }
            else{
                int ans=dis[y];
                int bg=0;
                while (!que.empty()){
                    int q=que.front();
                    if (bg==0) bg=q;
                    else if (bg==q) break;
                    que.pop();
                    ans=min(ans, getDis(y,q) );
                    que.push(q);
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
