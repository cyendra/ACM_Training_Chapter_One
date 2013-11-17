#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=411111;

char name_x[1111];
char name_y[1111];
map<string,int>mp;

struct ANS{
    int x;
    int y;
    int lca;
}ans[maxn];

int p[maxn];
int head[maxn];
int qhead[maxn];
struct NODE{
    int to;
    int next;
    int num;
    int lca;
};
NODE edges[maxn];
NODE qedges[maxn];
int edge,qedge;

void addedge(int u,int v)
{
    edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
}
void addqedge(int u,int v,int num)
{
    qedges[qedge].num=num;
    qedges[qedge].to=v;qedges[qedge].next=qhead[u];qhead[u]=qedge++;
}

int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

bool visit[maxn];

void LCA(int u)
{
    p[u]=u;
    int k;
    visit[u]=true;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (!visit[edges[k].to])
        {
            LCA(edges[k].to);
            p[edges[k].to]=u;
        }
    }
    for (k=qhead[u];k!=-1;k=qedges[k].next)
    {
        if (visit[qedges[k].to])
        {
            qedges[k].lca=find(qedges[k].to);
            qedges[k^1].lca=qedges[k].lca;
            //cerr<<qedges[k].lca<<"---lca---"<<qedges[k].num<<endl;
            ans[qedges[k].num].lca=qedges[k].lca;
        }
    }
}

int ind[maxn];

int dep[maxn];
void dfs(int u,int pat,int deep)
{
    int k;
    dep[u]=deep;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (edges[k].to!=pat)
        dfs(edges[k].to,u,deep+1);
    }
}

int main()
{
    int T,n,m;
    int x,y;
    int cnt;
    int root;
    scanf("%d",&T);
    while (T--)
    {
        //初始化
        memset(head,-1,sizeof(head));
        memset(qhead,-1,sizeof(qhead));
        memset(edges,0,sizeof(edges));
        memset(qedges,0,sizeof(qedges));
        memset(ind,0,sizeof(ind));
        memset(dep,0,sizeof(dep));
        memset(visit,0,sizeof(visit));
        mp.clear();
        edge=0;
        qedge=0;
        cnt=1;
        //读入数据
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n-1;i++)
        {
            scanf("%s%s",name_x,name_y);
            //映射
            if (mp[name_x]==0)
            {
                x=cnt;
                mp[name_x]=cnt++;
            }
            else
            {
                x=mp[name_x];
            }
            if (mp[name_y]==0)
            {
                y=cnt;
                mp[name_y]=cnt++;
            }
            else
            {
                y=mp[name_y];
            }
            //cerr<<"x y "<<x<<" "<<y<<endl;
            //添加边
            addedge(y,x);
            addedge(x,y);
            //计算入度
            ind[x]++;
        }
        //寻找根节点
        root=0;
        for (int i=1;i<cnt;i++)
        {
            if (ind[i]==0)
            {
                root=i;
            }
        }
        //cerr<<root<<"root"<<endl;
        //读入待处理数据
        for (int i=1;i<=m;i++)
        {
            scanf("%s%s",name_x,name_y);
            x=mp[name_x];
            y=mp[name_y];
            //添加正反询问边
            addqedge(x,y,i);
            addqedge(y,x,i);
            ans[i].x=x;
            ans[i].y=y;
        }
        //寻找lca#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=411111;

char name_x[1111];
char name_y[1111];
map<string,int>mp;

struct ANS{
    int x;
    int y;
    int lca;
}ans[maxn];

int p[maxn];
int head[maxn];
int qhead[maxn];
struct NODE{
    int to;
    int next;
    int num;
    int lca;
};
NODE edges[maxn];
NODE qedges[maxn];
int edge,qedge;

void addedge(int u,int v)
{
    edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
}
void addqedge(int u,int v,int num)
{
    qedges[qedge].num=num;
    qedges[qedge].to=v;qedges[qedge].next=qhead[u];qhead[u]=qedge++;
}

int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

bool visit[maxn];

void LCA(int u)
{
    p[u]=u;
    int k;
    visit[u]=true;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (!visit[edges[k].to])
        {
            LCA(edges[k].to);
            p[edges[k].to]=u;
        }
    }
    for (k=qhead[u];k!=-1;k=qedges[k].next)
    {
        if (visit[qedges[k].to])
        {
            qedges[k].lca=find(qedges[k].to);
            qedges[k^1].lca=qedges[k].lca;
            //cerr<<qedges[k].lca<<"---lca---"<<qedges[k].num<<endl;
            ans[qedges[k].num].lca=qedges[k].lca;
        }
    }
}

int ind[maxn];

int dep[maxn];
void dfs(int u,int pat,int deep)
{
    int k;
    dep[u]=deep;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (edges[k].to!=pat)
        dfs(edges[k].to,u,deep+1);
    }
}

int main()
{
    int T,n,m;
    int x,y;
    int cnt;
    int root;
    scanf("%d",&T);
    while (T--)
    {
        //初始化
        memset(head,-1,sizeof(head));
        memset(qhead,-1,sizeof(qhead));
        memset(edges,0,sizeof(edges));
        memset(qedges,0,sizeof(qedges));
        memset(ind,0,sizeof(ind));
        memset(dep,0,sizeof(dep));
        memset(visit,0,sizeof(visit));
        mp.clear();
        edge=0;
        qedge=0;
        cnt=1;
        //读入数据
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n-1;i++)
        {
            scanf("%s%s",name_x,name_y);
            //映射
            if (mp[name_x]==0)
            {
                x=cnt;
                mp[name_x]=cnt++;
            }
            else
            {
                x=mp[name_x];
            }
            if (mp[name_y]==0)
            {
                y=cnt;
                mp[name_y]=cnt++;
            }
            else
            {
                y=mp[name_y];
            }
            //cerr<<"x y "<<x<<" "<<y<<endl;
            //添加边
            addedge(y,x);
            addedge(x,y);
            //计算入度
            ind[x]++;
        }
        //寻找根节点
        root=0;
        for (int i=1;i<cnt;i++)
        {
            if (ind[i]==0)
            {
                root=i;
            }
        }
        //cerr<<root<<"root"<<endl;
        //读入待处理数据
        for (int i=1;i<=m;i++)
        {xn];
NODE qedges[maxn];
int edge,qedge;

void addedge(int u,int v)
{
    edges[edge].to=v;edges[edge].next=head[u];head[u]=edge++;
}
void addqedge(int u,int v,int num)
{
    qedges[qedge].num=num;
    qedges[qedge].to=v;qedges[qedge].next=qhead[u];qhead[u]=qedge++;
}

int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

bool visit[maxn];

void LCA(int u)
{
    p[u]=u;
    int k;
    visit[u]=true;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (!visit[edges[k].to])
        {
            LCA(edges[k].to);
            p[edges[k].to]=u;
        }
    }
    for (k=qhead[u];k!=-1;k=qedges[k].next)
    {
        if (visit[qedges[k].to])
        {
            qedges[k].lca=find(qedges[k].to);
            qedges[k^1].lca=qedges[k].lca;
            //cerr<<qedges[k].lca<<"---lca---"<<qedges[k].num<<endl;
            ans[qedges[k].num].lca=qedges[k].lca;
        }
    }
}

int ind[maxn];

int dep[maxn];
void dfs(int u,int pat,int deep)
{
    int k;
    dep[u]=deep;
    for (k=head[u];k!=-1;k=edges[k].next)
    {
        if (edges[k].to!=pat)
        dfs(edges[k].to,u,deep+1);
    }
}

int main()
{
    int T,n,m;
    int x,y;
    int cnt;
    int root;
    scanf("%d",&T);
    while (T--)
    {
        //初始化
        memset(head,-1,sizeof(head));
        memset(qhead,-1,sizeof(qhead));
        memset(edges,0,sizeof(edges));
        memset(qedges,0,sizeof(qedges));
        memset(ind,0,sizeof(ind));
        memset(dep,0,sizeof(dep));
        memset(visit,0,sizeof(visit));
        mp.clear();
        edge=0;
        qedge=0;
        cnt=1;
        //读入数据
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n-1;i++)
        {
            scanf("%s%s",name_x,name_y);
            //映射
            if (mp[name_x]==0)
            {
                x=cnt;
                mp[name_x]=cnt++;
            }
            else
            {
                x=mp[name_x];
            }
            if (mp[name_y]==0)
            {
                y=cnt;
                mp[name_y]=cnt++;
            }
            else
            {
                y=mp[name_y];
            }
            //cerr<<"x y "<<x<<" "<<y<<endl;
            //添加边
            addedge(y,x);
            addedge(x,y);
            //计算入度
            ind[x]++;
        }
        //寻找根节点
        root=0;
        for (int i=1;i<cnt;i++)
        {
            if (ind[i]==0)
            {
                root=i;
            }
        }
        //cerr<<root<<"root"<<endl;
        //读入待处理数据
        for (int i=1;i<=m;i++)
        {
            scanf("%s%s",name_x,name_y);
            x=mp[name_x];
            y=mp[name_y];
            //添加正反询问边
            addqedge(x,y,i);
            addqedge(y,x,i);
            ans[i].x=x;
            ans[i].y=y;
        }
        //寻找lca
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i].x==ans[i].y) as=0;
            printf("%d\n",as);
        }
    }
    return 0;
}

        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i
            scanf("%s%s",name_x,name_y);
            x=mp[name_x];
            y=mp[name_y];
            //添加正反询问边
            addqedge(x,y,i);
            addqedge(y,x,i);
            ans[i].x=x;
            ans[i].y=y;
        }
        //寻找lca
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度[k].next)
    {
        if (edges[k].to!=pat)
        dfs(edges[k].to,u,deep+1);
    }
}

int main()
{
    int T,n,m;
    int x,y;
    int cnt;
    int root;
    scanf("%d",&T);
    while (T--)
    {
        //初始化
        memset(head,-1,sizeof(head));
        memset(qhead,-1,sizeof(qhead));
        memset(edges,0,sizeof(edges));
        memset(qedges,0,sizeof(qedges));
        memset(ind,0,sizeof(ind));
        memset(dep,0,sizeof(dep));
        memset(visit,0,sizeof(visit));
        mp.clear();
        edge=0;
        qedge=0;
        cnt=1;
        //读入数据
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n-1;i++)
        {
            scanf("%s%s",name_x,name_y);
            //映射
            if (mp[name_x]==0)
            {
                x=cnt;
                mp[name_x]=cnt++;
            }
            else
            {
                x=mp[name_x];
            }
            if (mp[name_y]==0)
            {
                y=cnt;
                mp[name_y]=cnt++;
            }
            else
            {
                y=mp[name_y];
            }
            //cerr<<"x y "<<x<<" "<<y<<endl;
            //添加边
            addedge(y,x);
            addedge(x,y);
            //计算入度
            ind[x]++;
        }
        //寻找根节点
        root=0;
        for (int i=1;i<cnt;i++)
        {
            if (ind[i]==0)
            {
                root=i;
            }
        }
        //cerr<<root<<"root"<<endl;
        //读入待处理数据
        for (int i=1;i<=m;i++)
        {
            scanf("%s%s",name_x,name_y);
            x=mp[name_x];
            y=mp[name_y];
            //添加正反询问边
            addqedge(x,y,i);
            addqedge(y,x,i);
            ans[i].x=x;
            ans[i].y=y;
        }
        //寻找lca
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i].x==ans[i].y) as=0;
            printf("%d\n",as);
        }
    }
    return 0;
}

        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i
            scanf("%s%s",name_x,name_y);
            x=mp[name_x];
            y=mp[name_y];
            //添加正反询问边
            addqedge(x,y,i);
            addqedge(y,x,i);
            ans[i].x=x;
            ans[i].y=y;
        }
        //寻找lca
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i].x==ans[i].y) as=0;
            printf("%d\n",as);
        }
    }
    return 0;
}

        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;

        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i].x==ans[i].y) as=0;
            printf("%d\n",as);
        }
    }
    return 0;
}

        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        LCA(root);
        //计算深度
        dfs(root,-1,1);
        //for (int i=1;i<=n;i++) cerr<<dep[i]<<endl;
        //处理询问
        //cerr<<"aaaaaaaaaaaaaaaa"<<endl;
        for (int i=1;i<=m;i++)
        {
            int as=0;
            as=dep[ans[i].x]-dep[ans[i].lca];
            if (ans[i].lca!=ans[i].y) as++;
            if (ans[i].x==ans[i].y) as=0;
            printf("%d\n",as);
        }
    }
    return 0;
}

/*
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define maxn 400010
map<string,int>data;
int n;
struct Node{
    int v, w;
    Node(int v_, int w_){
        v= v_, w= w_;
    }
};
vector<Node>g[maxn];

int father[maxn];
int dis[maxn];
int dep[maxn];
int indeg[maxn];
void dfs(int u, int fa, int deep){
    father[u]= fa;
    dep[u]= deep;
    for(int i=0; i<g[u].size(); ++i){
        int v= g[u][i].v;
        if(v==fa) continue; //

        dis[v]= dis[u] + g[u][i].w;
        dfs(v, u, deep+1);
    }
}

int p[maxn][30];
void Init_LCA(){
    for(int j=0; (1<<j)<=n; ++j)
        for(int i=1; i<=n; ++i)
            p[i][j]= -1;
    for(int i=1; i<=n; ++i) p[i][0]= father[i];
    for(int j=1; (1<<j)<=n; ++j)
        for(int i=1; i<=n; ++i)
            if( p[i][j-1] != -1 )
                p[i][j]= p[ p[i][j-1] ][ j-1 ];
}

int LCA(int x, int y){
    if( dep[x] < dep[y] ) swap(x, y);
    int i,lg;
    for(lg=0; (1<<lg)<=dep[x]; ++lg);
    --lg;
    /// 使x往上走直到和y在同一水平线上；
    for(i=lg; i>=0; --i)
        if( dep[x] - (1<<i) >= dep[y] )
            x= p[x][i];
    if( x==y ) return x;
    /// 此时x，y在同一水平线上，使x，y同时以相同的速度(2^j)往上走；
    for(i=lg; i>=0; --i)
        if( p[x][i]!=-1 && p[x][i]!=p[y][i] )
            x= p[x][i], y= p[y][i];
    return father[x];
}

int main(){
    int T, m;
    char a[100005],b[100005];
    cin>>T;
    while(T--){
        data.clear();
        cin>>n>>m;
        memset(indeg,0,sizeof(indeg));
        int cnt=1;
        for(int i=1; i<=n; ++i) g[i].clear();
        for(int i=1; i<n; ++i){
            int x, y;
            scanf("%s%s", a,b);
            if(data[a]==0) data[a]=cnt++;
            if(data[b]==0) data[b]=cnt++;
            x=data[a],y=data[b];
            indeg[x]++;
            g[x].push_back( Node(y, 1) );
            g[y].push_back( Node(x, 1) );
        }
        int start=1;
        for(int i=1;i<=n;i++)
        if(indeg[i]==0) {start=i;break;}
        dis[start]= 0;
        dfs(start, -1, 0);

        Init_LCA();
//        for(int i=1;i<=n;i++)
//        cout<<dis[i]<<" ";
//        cout<<endl;
        while(m--){
            int x, y;
            scanf("%s%s", a, b);
            x=data[a],y=data[b];
            int lcaxy=LCA(x,y);
            if(y==lcaxy) printf("%d\n",dis[x]-dis[y]);
            else if(x==lcaxy) puts("1");
            else printf("%d\n", dis[x] - dis[ LCA(x, y)]+1);
        }
    }
}
*/
