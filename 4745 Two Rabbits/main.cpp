#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <queue>
using namespace std;

const int maxn=1111;
const int maxm=1111;
const int INF=0x3f3f3f;
int a[maxn];
int f[maxn][maxn];
int n;
struct EdgeNode{
    int to;
    int w;
    int next;
};
/*==============================================*\
 | BellmanFord+队列优化
 | INIT: init(n);addedge(u,v,c);节点编号0~n
 | CALL: spfa(int s):bool;dist[]:最短路
\*==============================================*/
struct BellmanFord{
    EdgeNode edges[maxm];
    int head[maxn],edge,n;
    bool vis[maxn];
    int outque[maxn];
    queue<int>que;
    int dis[maxn];
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
    }
    void init(int n){
        memset(head,-1,sizeof(head));
        edge=0;
        this->n=n;
    }
    bool spfa(int s){
        int top;
        for (int i=0;i<=n;i++) dis[i]=INF;
        memset(vis,0,sizeof(vis));
        memset(outque,0,sizeof(outque));
        while (!que.empty()) que.pop();
        que.push(s);
        vis[s]=true;
        dis[s]=0;
        while (!que.empty()){
            top=que.front();
            que.pop();
            vis[top]=false;
            outque[top]++;
            if (outque[top]>n) return false;
            for (int i=head[top];i!=-1;i=edges[i].next){
                int v=edges[i].to;
                if (dis[v]==INF||dis[v]>dis[top]+edges[i].w){
                    dis[v]=dis[top]+edges[i].w;
                    if (!vis[v]){
                        vis[v]=true;
                        que.push(v);
                    }
                }
            }
        }
        return true;
    }
};

int prev(int x){
    return (x-1+n)%n;
}
int next(int x){
    return (x+1)%n;
}
int dp(int l,int r){
    if (l==r) return 1;
    if (next(l)==r) return 1+(a[l]==a[r]);
    if (f[l][r]!=-1) return f[l][r];
    if (a[l]==a[r]) return f[l][r]=dp(next(l),prev(r))+2;
    return f[l][r]=max(dp(next(l),r),dp(l,prev(r)));
}
int main()
{
    int ans;
    while (~scanf("%d",&n)){
        if (n==0) break;
        ans=0;
        memset(f,-1,sizeof(f));
        for (int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if (n==1) ans=1;
        else if (n==2) ans=2;
        else{
            for (int i=0;i<n;i++){
                ans=max(ans,dp(next(i),prev(i))+1);
                //ans=max(ans,dp(i,prev(i)));
                ans=max(ans,dp(next(i),i));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
