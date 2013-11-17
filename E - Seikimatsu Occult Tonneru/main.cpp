
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int OO=1e9;
const int maxm=111111;
const int maxn=999;

struct edgenode
{
    int to,flow,next;
};

struct Dinic
{
    int node,src,dest,edge;
    int head[maxn],work[maxn],dis[maxn],q[maxn];
    edgenode edges[maxm];

    void prepare(int _node,int _src,int _dest)
    {
        node=_node,src=_src,dest=_dest;
        for (int i=0; i<node; i++) head[i]=-1;
        edge=0;
    }

    void addedge(int u,int v,int c)
    {
        edges[edge].flow=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
        edges[edge].flow=0,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
    }

    bool Dinic_bfs()
    {
        int i,u,v,l,r=0;
        for (i=0; i<node; i++) dis[i]=-1;
        dis[q[r++]=src]=0;
        for (l=0; l<r; l++){
            for (i=head[u=q[l]]; i!=-1; i=edges[i].next){
                if (edges[i].flow&&dis[v=edges[i].to]<0){
                    dis[q[r++]=v]=dis[u]+1;
                    if (v==dest) return true;
                }
            }
        }
        return false;
    }

    int Dinic_dfs(int u,int exp)
    {
        if (u==dest) return exp;
        for (int &i=work[u],v,tmp; i!=-1; i=edges[i].next){
            if (edges[i].flow&&dis[v=edges[i].to]==dis[u]+1&&
                (tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0){
                edges[i].flow-=tmp;
                edges[i^1].flow+=tmp;
                return tmp;
            }
        }
        return 0;
    }

    int Dinic_flow()
    {
        int i,ret=0,delta;
        while (Dinic_bfs()){
            for (i=0; i<node; i++) work[i]=head[i];
            while ( delta=Dinic_dfs(src,OO) ) ret+=delta;
        }
        return ret;
    }

}solver;

int ogc[14];
int cst[14];
int cnt;
int ww[maxn];
int main()
{
    int n,m;
    int mincost,maxnum,cost,num;
    while (~scanf("%d%d",&n,&m))
    {
        cnt=0;
        solver.prepare(n+2,0,n+1);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&ww[i]);
            solver.addedge(solver.src,i,ww[i]);
        }
        for (int i=0;i<m;i++)
        {
            int u,v,w,p;
            scanf("%d%d%d%d",&u,&v,&w,&p);
            if (p<0)
            {
                solver.addedge(u,solver.dest,w);
                solver.addedge(u,v,OO);
            }
            if (p>0)
            {
                solver.addedge(u,v,1);
                cst[cnt]=w;
                ogc[cnt++]=solver.edge-2;

            }
            if (p==0)
            {
                solver.addedge(u,v,OO);
            }
        }
        mincost=0;
        maxnum=0;
        for (int i=0;i<(1<<cnt);i++)
        {
            cost=0;
            num=0;
            for (int k=0;k<solver.edge;k+=2)
            {
                solver.edges[k].flow+=solver.edges[k^1].flow;
                solver.edges[k^1].flow=0;
            }
            for (int j=0;j<cnt;j++)
            {
                if (i&(1<<j))
                {
                    solver.edges[ogc[j]].flow=OO;
                    cost+=cst[j];
                }
                else
                {
                    solver.edges[ogc[j]].flow=1;
                }
            }
            num=solver.Dinic_flow();
            if (num>maxnum)
            {
                maxnum=num;
                mincost=cost;
            }
            else if (num==maxnum&&cost<mincost)
            {
                mincost=cost;
            }
        }
        if (maxnum>0)
        {
            printf("%d %d\n",maxnum,mincost);
        }
        else
        {
            puts("Poor Heaven Empire");
        }

    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int OO=1e9;
const int maxm=111111;
const int maxn=999;

struct edgenode
{
    int to,flow,next;
};

struct Dinic
{
    int node,src,dest,edge;
    int head[maxn],work[maxn],dis[maxn],q[maxn];
    edgenode edges[maxm];

    void prepare(int _node,int _src,int _dest)
    {
        node=_node,src=_src,dest=_dest;
        for (int i=0; i<node; i++) head[i]=-1;
        edge=0;
    }

    void addedge(int u,int v,int c)
    {
        edges[edge].flow=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
        edges[edge].flow=0,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
    }

    bool Dinic_bfs()
    {
        int i,u,v,l,r=0;
        for (i=0; i<node; i++) dis[i]=-1;
        dis[q[r++]=src]=0;
        for (l=0; l<r; l++){
            for (i=head[u=q[l]]; i!=-1; i=edges[i].next){
                if (edges[i].flow&&dis[v=edges[i].to]<0){
                    dis[q[r++]=v]=dis[u]+1;
                    if (v==dest) return true;
                }
            }
        }
        return false;
    }

    int Dinic_dfs(int u,int exp)
    {
        if (u==dest) return exp;
        for (int &i=work[u],v,tmp; i!=-1; i=edges[i].next){
            if (edges[i].flow&&dis[v=edges[i].to]==dis[u]+1&&
                (tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0){
                edges[i].flow-=tmp;
                edges[i^1].flow+=tmp;
                return tmp;
            }
        }
        return 0;
    }

    int Dinic_flow()
    {
        int i,ret=0,delta;
        while (Dinic_bfs()){
            for (i=0; i<node; i++) work[i]=head[i];
            while ( delta=Dinic_dfs(src,OO) ) ret+=delta;
        }
        return ret;
    }

}solver;

int thead[maxn];
edgenode tedges[maxm];
int tedge_num;

struct OGC{
    int u,v,w;
}ogc[14];
int cnt;
int ww[maxn];
int main()
{
    int n,m;
    int mincost,maxnum,cost,num;
    while (~scanf("%d%d",&n,&m))
    {
        cnt=0;
        solver.prepare(n+2,0,n+1);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&ww[i]);
            solver.addedge(solver.src,i,ww[i]);
        }
        for (int i=0;i<m;i++)
        {
            int u,v,w,p;
            scanf("%d%d%d%d",&u,&v,&w,&p);
            if (p<0)
            {
                solver.addedge(u,solver.dest,w);
                solver.addedge(u,v,OO);
            }
            if (p>0)
            {
                //solver.addedge(u,v,1);
                ogc[cnt].u=u;
                ogc[cnt].v=v;
                ogc[cnt].w=w;
                cnt++;
            }
            if (p==0)
            {
                solver.addedge(u,v,OO);
            }
        }
        memcpy(thead,solver.head,sizeof(thead));
        memcpy(tedges,solver.edges,sizeof(tedges));
        tedge_num=solver.edge;
        mincost=0;
        maxnum=0;
        for (int i=0;i<(1<<cnt);i++)
        {
            solver.edge=tedge_num;
            memcpy(solver.head,thead,sizeof(solver.head));
            memcpy(solver.edges,tedges,sizeof(solver.edges));
            cost=0;
            num=0;
            for (int j=0;j<cnt;j++)
            {
                if (i&(1<<j))
                {
                    solver.addedge(ogc[j].u,ogc[j].v,OO);
                    cost+=ogc[j].w;
                }
                else
                {
                    solver.addedge(ogc[j].u,ogc[j].v,1);
                }
            }
            num=solver.Dinic_flow();
            if (num>maxnum)
            {
                maxnum=num;
                mincost=cost;
            }
            else if (num==maxnum&&cost<mincost)
            {
                mincost=cost;
            }
        }
        if (maxnum>0)
        {
            printf("%d %d\n",maxnum,mincost);
        }
        else
        {
            puts("Poor Heaven Empire");
        }

    }
    return 0;
}
*/
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int maxn=1111;
const int maxm=1111111;
const int INF=1e9;

struct Edge{
    int from,to,cap,flow;
};

struct Dinic{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];

    void init(int n){
        this->n=n;
        for (int i=0;i<n;i++) G[i].clear();
        edges.clear();
        m=0;
    }

    void addedge(int from,int to,int cap){
        edges.push_back((Edge){from,to,cap,0});
        edges.push_back((Edge){to,from,0,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS(){
        memset(vis,0,sizeof(vis));
        queue<int>que;
        que.push(s);
        d[s]=0;
        vis[s]=true;
        while (!que.empty()){
            int x=que.front();que.pop();
            for (int i=0;i<G[x].size();i++){
                Edge& e=edges[G[x][i]];
                if (!vis[e.to]&&e.cap>e.flow){
                    vis[e.to]=true;
                    d[e.to]=d[x]+1;
                    que.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a){
        if (x==t||a==0) return a;
        int flow=0,f;
        for (int& i=cur[x];i<G[x].size();i++){
            Edge& e=edges[G[x][i]];
            if (d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (a==0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t){
        this->s=s;
        this->t=t;
        int flow=0;
        while (BFS()){
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }

}solver;

vector<Edge>tmpedges;

struct OGC{
    int u,v,w;
}ogc[14];
int cnt;
int ww[maxn];
int main()
{
    int n,m;
    int mincost,maxnum,cost,num;
    int s,t;
    while (~scanf("%d%d",&n,&m))
    {
        cnt=0;
        solver.init(n+2);
        s=0;
        t=n+1;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&ww[i]);
            solver.addedge(s,i,ww[i]);
        }
        for (int i=0;i<m;i++)
        {
            int u,v,w,p;
            scanf("%d%d%d%d",&u,&v,&w,&p);
            if (p<0)
            {
                solver.addedge(u,t,w);
                solver.addedge(u,v,INF);
            }
            if (p>0)
            {
                //solver.addedge(u,v,1);
                ogc[cnt].u=u;
                ogc[cnt].v=v;
                ogc[cnt].w=w;
                cnt++;
            }
            if (p==0)
            {
                solver.addedge(u,v,INF);
            }
        }
        tmpedges=solver.edges;
        mincost=0;
        maxnum=0;
        for (int i=0;i<(1<<cnt);i++)
        {
            solver.edges=tmpedges;
            cost=0;
            num=0;
            for (int j=0;j<cnt;j++)
            {
                if (i&(1<<j))
                {
                    solver.addedge(ogc[j].u,ogc[j].v,INF);
                    cost+=ogc[j].w;
                }
                else
                {
                    solver.addedge(ogc[j].u,ogc[j].v,1);
                }
            }
            num=solver.Maxflow(s,t);
            if (num>maxnum)
            {
                maxnum=num;
                mincost=cost;
            }
            else if (num==maxnum&&cost<mincost)
            {
                mincost=cost;
            }
        }
        if (maxnum>0)
        {
            printf("%d %d\n",maxnum,mincost);
        }
        else
        {
            puts("Poor Heaven Empire");
        }

    }
    return 0;
}
*/
