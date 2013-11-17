#include <iostream>
#include <cstdio>

using namespace std;

const int OO=1e9;//无穷大
const int maxm=11111111;//边的最大数量，为原图的两倍
const int maxn=12222;//点的最大数量

int node,src,dest,edge;//node节点数，src源点，dest汇点，edge边数
int head[maxn],p[maxn],dis[maxn],q[maxn],vis[maxn];//head链表头，p记录可行流上节点对应的反向边，dis计算距离

struct edgenode
{
    int to;//边的指向
    int flow;//边的容量
    int cost;//边的费用
    int next;//链表的下一条边
} edges[maxm];

void prepare(int _node,int _src,int _dest);
void addedge(int u,int v,int f,int c);
bool spfa();

inline int min(int a,int b)
{
    return a<b?a:b;
}

inline void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++)
    {
        head[i]=-1;
        vis[i]=false;
    }
    edge=0;
}

void addedge(int u,int v,int f,int c)
{
    edges[edge].flow=f;
    edges[edge].cost=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].cost=-c;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for (i=0; i<node; i++) dis[i]=OO;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for (l=0; l!=r; ((++l>=maxn)?l=0:1))
    {
        for (i=head[u=q[l]],vis[u]=false; i!=-1; i=edges[i].next)
        {
            if (edges[i].flow&&dis[v=edges[i].to]>(tmp=dis[u]+edges[i].cost))
            {
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

int spfaflow()
{
    int i,ret=0,delta;
    while (spfa())
    {
        //按记录原路返回求流量

        for (i=p[dest],delta=OO; i>=0; i=p[edges[i].to])
        {
            delta=min(delta,edges[i^1].flow);
        }
        for (int i=p[dest]; i>=0; i=p[edges[i].to])
        {
            edges[i].flow+=delta;
            edges[i^1].flow-=delta;
        }
        ret+=delta*dis[dest];
    }
    return ret;
}

int n;
int a[11111];

int main()
{
    int sum;
    //int avr;
    while (~scanf("%d",&n))
    {
        prepare(n+n+2,0,n+n+1);

        sum=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            addedge(src,i,a[i],0);
            addedge(i,i+n,OO,0);
            sum+=a[i];
        }
        sum/=n;
        for(int u=1;u<=n;++u)
        {
            addedge(u+n,dest,sum,0);
            int v=u<n?u+1:1;
            addedge(u+n,v,OO,1);
            addedge(v+n,u,OO,1);
        }

        printf("%d\n",spfaflow());
    }
    return 0;
}


/*
int main()
{
    int sum;
    int avr;
    while (~scanf("%d",&n))
    {
        prepare(n+2,0,n+1);

        sum=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);

            sum+=a[i];
        }
        avr=sum/n;
        for (int i=1;i<=n;i++)
        {
            addedge(src,i,a[i],0);
            addedge(i,dest,avr,0);
        }
        for (int i=1;i<n;i++)
        {
            addedge(i,i+1,OO,1);
            addedge(i+1,i,OO,1);
        }
        addedge(n,1,OO,1);
        addedge(1,n,OO,1);

        printf("%d\n",spfaflow());
    }
    return 0;
}


*/





/*
                addedge(i,i+n,OO,0);
    addedge(src,i,a[i],0);
    for (int i=1;i<=n;i++)
    {
        addedge(i+n,dest,avr,0);
        int v=i<n?i+1:1;
        addedge(i,v+n,OO,1);
        addedge(v,i+n,OO,1);
    }

*/

/*

        int j;

        for (int i=1; i<=n; i++)
        {
            a[i]-=avr;
        }
        for (int i=1; i<=n; i++)
        {
            if (a[i]>0) addedge(src,i,a[i],0);
            if (a[i]<0) addedge(i+n,dest,-a[i],0);

            j=i-1;
            if (j<1) j=n;
            addedge(i,j+n,OO,1);
            addedge(i,j,OO,1);

            j=i+1;
            if (j>n) j=1;
            addedge(i,i+n,OO,1);
            addedge(i,j,OO,1);
        }

*/
