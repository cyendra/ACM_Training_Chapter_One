#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=1111;
const int INF=1e8;

void dfs(int u);//������ǿ��ͨ
void find_scc(int n);//��ǿ��ͨ
void tops(int n);//��������

int w[maxn];//��Ȩ
vector<int>a[maxn];//DAGͼ
vector<int>G[maxn];//ԭͼ
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;//Tarjan
stack<int> S;//Tarjan
int indegree[maxn];//���
int ans;
bool hash[maxn][maxn];
//-----Tarjan------

void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    int len=G[u].size();
    for (int i=0;i<len;i++)
    {
        int v=G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u]=min( lowlink[u], lowlink[v] );
        }
        else if (!sccno[v])
        {
            lowlink[u]=min( lowlink[u], pre[v] );
        }
    }
    if (lowlink[u]==pre[u])
    {
        scc_cnt++;
        while (true)
        {
            int x=S.top();
            S.pop();
            sccno[x]=scc_cnt;
            w[scc_cnt]++;
            if (x==u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    memset(w,0,sizeof(w));
    while (!S.empty()) S.pop();
    for (int i=1;i<=n;i++)
    {
        if (!pre[i]) dfs(i);
    }
}


int f[maxn];
int DP(int u)
{
    int ret=0;
    int sz=a[u].size();
    for (int i=0;i<sz;i++)
    {
        int v=a[u][i];
        ret=max(ret,DP(v));
    }
    f[u]=ret+w[u];
    return f[u];
}


//-----------------

int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while (T--)
    {
        //init()
        memset(indegree,0,sizeof(indegree));
        memset(hash,0,sizeof(hash));
        memset(f,0,sizeof(f));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            G[i].clear();
            a[i].clear();
        }
        for (int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        //ǿ��ͨ
        find_scc(n);
        //����
        for (int i=1;i<=n;i++)
        {
            int sz=G[i].size();
            for (int j=0;j<sz;j++)
            {
                int v=G[i][j];
                if (sccno[i]!=sccno[v]&&!hash[sccno[i]][sccno[v]])
                {
                    a[sccno[i]].push_back(sccno[v]);
                    hash[sccno[i]][sccno[v]]=true;
                    indegree[sccno[v]]++;
                }
            }
        }
        ans=0;
        for (int i=1;i<=n;i++)
        {
            if (indegree[i]==0)
            {
                ans=max(ans,DP(i));
            }
        }

        //���
        printf("%d\n",ans);
    }
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn=1111;
const int INF=1e8;

void dfs(int u);//������ǿ��ͨ
void find_scc(int n);//��ǿ��ͨ
void tops(int n);//��������

int w[maxn];//��Ȩ
vector<int>a[maxn];//DAGͼ
vector<int>G[maxn];//ԭͼ
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt;//Tarjan
stack<int> S;//Tarjan
int dist[maxn];//dp
int indegree[maxn];//���
int top_que[maxn];//top����
int top_iq=0;//����ָ��
int ans;
bool hash[maxn][maxn];
//-----Tarjan------

void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    int len=G[u].size();
    for (int i=0;i<len;i++)
    {
        int v=G[u][i];
        if (!pre[v])
        {
            dfs(v);
            lowlink[u]=min( lowlink[u], lowlink[v] );
        }
        else if (!sccno[v])
        {
            lowlink[u]=min( lowlink[u], pre[v] );
        }
    }
    if (lowlink[u]==pre[u])
    {
        scc_cnt++;
        while (true)
        {
            int x=S.top();
            S.pop();
            sccno[x]=scc_cnt;
            w[scc_cnt]++;
            if (x==u) break;
        }
    }
}
void find_scc(int n)
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    memset(w,0,sizeof(w));
    while (!S.empty()) S.pop();
    for (int i=1;i<=n;i++)
    {
        if (!pre[i]) dfs(i);
    }
}

//top----------------

void tops(int n)
{
    int i,j,sz,u,v;
    top_iq=0;
    for (i=1;i<=n;i++)
    {
        if (indegree[i]==0)
        {
            top_que[top_iq++]=i;
        }
    }
    for (i=0;i<top_iq;i++)
    {
        u=top_que[i];
        for (j=0,sz=a[u].size();j<sz;j++)
        {
            if ((--indegree[v=a[u][j]])==0)
            {
                top_que[top_iq++]=v;
            }
        }
    }
}

//DAG--------------

void DAG(int n)
{
    int i,k,sz,u,v;
    ans=0;
    for (i=1;i<=n;i++)
    {
        dist[i]=w[i];
    }
    for (i=0;i<top_iq;i++)
    {
        u=top_que[i];
        for (k=0,sz=a[u].size();k<sz;k++)
        {
            v=a[u][k];
            if (dist[u]+w[v]>dist[v])
            {
                dist[v]=dist[u]+w[v];
                if (dist[v]>ans) ans=dist[v];
            }
        }
    }
}

//-----------------

int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while (T--)
    {
        //init()
        memset(indegree,0,sizeof(indegree));
        memset(hash,0,sizeof(hash));
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            G[i].clear();
            a[i].clear();
        }
        for (int i=1;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
        }
        //ǿ��ͨ
        find_scc(n);
        //����
        for (int i=1;i<=n;i++)
        {
            int sz=G[i].size();
            for (int j=0;j<sz;j++)
            {
                int v=G[i][j];
                if (sccno[i]!=sccno[v]&&!hash[sccno[i]][sccno[v]])
                {
                    a[sccno[i]].push_back(sccno[v]);
                    hash[sccno[i]][sccno[v]]=true;
                    indegree[sccno[v]]++;
                }
            }
        }
        //��������
        tops(scc_cnt);

        //for (int i=1;i<=scc_cnt;i++){for (int j=0;j<a[i].size();j++){cerr<<i<<" "<<a[i][j]<<endl;}}
        //for (int i=0;i<top_iq;i++){cerr<<top_que[i]<<" ";}cerr<<endl;
        //for (int i=1;i<=scc_cnt;i++) cerr<<w[i]<<" ";cerr<<endl;
        //DAGDP
        DAG(scc_cnt);
        //���
        printf("%d\n",ans);
    }
    return 0;
}

*/
