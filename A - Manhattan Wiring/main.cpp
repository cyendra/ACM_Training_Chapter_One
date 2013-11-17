#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int dir[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
const int INF=0x3f3f3f3f;//无穷大
const int maxm=1111111;//边的最大数量，为原图的两倍
const int maxn=2222;//点的最大数量
struct edgenode{
    int to;//边的指向
    int flow;//边的容量
    int cost;//边的费用
    int next;//链表的下一条边
};
struct MinCost{
    edgenode edges[maxm];
    int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
    int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];//head链表头，p记录可行流上节点对应的反向边，dis计算距离
    void prepare(int _node=0,int _src=0,int _dest=0){
        node=_node,src=_src,dest=_dest;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        edge=0;
    }
    void addedge(int u,int v,int f,int c){
        printf("u=%d v=%d f=%d c=%d\n",u,v,f,c);
        edges[edge].flow=f;edges[edge].cost=c;edges[edge].to=v;
        edges[edge].next=head[u];head[u]=edge++;
        edges[edge].flow=0;edges[edge].cost=-c;edges[edge].to=u;
        edges[edge].next=head[v];head[v]=edge++;
    }
    bool spfa(){
        int i,u,v,l,r=0,tmp;
        for (i=0;i<node;i++) dis[i]=INF;
        dis[q[r++]=src]=0;
        p[src]=p[dest]=-1;
        for (l=0;l!=r;((++l>=maxn)?l=0:l)){
            for (i=head[u=q[l]],vis[u]=false;i!=-1;i=edges[i].next){
                if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost)){
                    dis[v]=tmp;
                    p[v]=i^1;
                    if (vis[v]) continue;
                    vis[q[r++]=v]=true;
                    if (r>=maxn) r=0;
                }
            }
        }
        return p[dest]>=0;
    }
    int spfaflow(){
        int i,ret=0,delta;
        while (spfa()){//按记录原路返回求流量
            for (i=p[dest],delta=INF;i>=0;i=p[edges[i].to]){
                delta=min(delta,edges[i^1].flow);
            }
            for (int i=p[dest];i>=0;i=p[edges[i].to]){
                edges[i].flow+=delta;
                edges[i^1].flow-=delta;
            }
            ret+=delta*dis[dest];
        }
        return ret;
    }
    void output(int u){
        cout<<u<<endl;
        for (int i=head[u];i!=-1;i=edges[i].next){
            int v=edges[i].to;
            if (edges[i].flow==0&&((i&1)==0)) output(v);
        }
    }
}solver;
int n,m;

bool check(int x,int y){
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

int main()
{
    int num,src,dest;
    int amp[15][15];
    int st[15][15];
    while (~scanf("%d%d",&n,&m)){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                scanf("%d",&amp[i][j]);
                st[i][j]=(i-1)*m+(j-1)+1;
            }
        }
        num=n*m;
        src=0;
        dest=num*2+1;
        solver.prepare(num*2+2,src,dest);
        bool b2=false,b3=false;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (amp[i][j]!=1){
                    solver.addedge(st[i][j],st[i][j]+num,1,1);
                    for (int k=0;k<4;k++){
                        int dx=i+dir[k][0];
                        int dy=j+dir[k][1];
                        if (check(dx,dy)){
                            //solver.addedge(st[dx][dy]+num,st[i][j],1,1);
                            if (amp[dx][dy]!=1)
                                solver.addedge(st[i][j]+num,st[dx][dy],1,0);
                        }
                    }
                }
                if (amp[i][j]==2){
                    if (b2){
                        solver.addedge(st[i][j]+num,dest,1,0);
                    }else{
                        b2=true;
                        solver.addedge(src,st[i][j],1,0);
                    }
                }
                if (amp[i][j]==3){
                    if (b3){
                        solver.addedge(st[i][j]+num,dest,1,0);
                    }else{
                        b3=true;
                        solver.addedge(src,st[i][j],1,0);
                    }
                }
            }
        }
        printf("%d\n",solver.spfaflow()-2);
        solver.output(src);
    }
    return 0;
}
