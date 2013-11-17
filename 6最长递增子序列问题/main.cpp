#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OO=1e9;//�����
const int maxm=111111;//�ߵ����������Ϊԭͼ������
const int maxn=999;//����������

int node,src,dest,edge;//node�ڵ�����srcԴ�㣬dest��㣬edge����
int head[maxn],work[maxn],dis[maxn],q[maxn];//head����ͷ��work��ʱ��ͷ��dis�������

struct edgenode
{
    int to;//�ߵ�ָ��
    int flow;//�ߵ�����
    int next;//�������һ����
} edges[maxm];

//��ʼ������ͼ����Ϣ
void prepare(int _node,int _src,int _dest)
{
    node=_node;
    src=_src;
    dest=_dest;
    for (int i=0; i<node; i++) head[i]=-1;
    edge=0;
}

//���һ����u��v����Ϊc�ı�
void addedge(int u,int v,int c)
{
    edges[edge].flow=c;
    edges[edge].to=v;
    edges[edge].next=head[u];
    head[u]=edge++;
    edges[edge].flow=0;
    edges[edge].to=u;
    edges[edge].next=head[v];
    head[v]=edge++;
}

//���Ѽ����ÿ������Դ�����̾��룬������ܵ�����˵���㷨����
bool Dinic_bfs()
{
    int u,v,r=0;
    for (int i=0; i<node; i++) dis[i]=-1;
    q[r++]=src;
    dis[src]=0;
    for (int l=0; l<r; l++)
    {
        u=q[l];
        for (int i=head[u]; i!=-1; i=edges[i].next)
        {
            v=edges[i].to;
            if (edges[i].flow&&dis[v]<0)
            {
                //�����߱���Ҫ��ʣ������
                q[r++]=v;
                dis[v]=dis[u]+1;
                if (v==dest) return true;
            }
        }
    }
    return false;
}

//Ѱ�ҿ�����������·�㷨�����ڵ�ľ������ң��ӿ��ٶ�
int Dinic_dfs(int u,int exp)
{
    int v,tmp;
    if (u==dest) return exp;
    //work����ʱ����ͷ�������� i������������Ѱ�ҹ��ı߲���Ѱ��
    for (int &i=work[u]; i!=-1; i=edges[i].next)
    {
        v=edges[i].to;
        if (edges[i].flow&&dis[v]==dis[u]+1&&(tmp=Dinic_dfs(v,min(exp,edges[i].flow)))>0)
        {
            edges[i].flow-=tmp;
            edges[i^1].flow+=tmp;
            //������������ı�
            return tmp;
        }
    }
    return 0;
}

//�������ֱ��û�п�����
int Dinic_flow()
{
    int ret=0,tmp;
    while (Dinic_bfs())
    {
        for (int i=0; i<node; i++) work[i]=head[i];
        while ( tmp=Dinic_dfs(src,OO) ) ret+=tmp;
    }
    return ret;
}

int n,s;
int a[1111];
int f[1111];

int main()
{
    while (~scanf("%d",&n))
    {
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        s=0;
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=1; i<=n; i++)
        {
            f[i]=1;
            for (int j=1; j<i; j++)
            {
                if (f[j]+1>f[i]&&a[j]<a[i])
                {
                    f[i]=f[j]+1;
                }
            }
            if (f[i]>s) s=f[i];
        }
        cout<<s<<endl;

        //for (int i=1;i<=n;i++) cerr<<f[i]<<" ";cerr<<endl;

        prepare(n*2+2,0,n*2+1);
        for (int i=1; i<=n; i++)
        {
            if (f[i]==1) addedge(src,i,1);
            if (f[i]==s) addedge(i+n,dest,1);
            addedge(i,i+n,1);
            for (int j=1; j<i; j++)
            {
                if (f[j]+1==f[i]&&a[i]>a[j]) addedge(j+n,i,1);
            }
        }
        int ans1=Dinic_flow();
        cout<<ans1<<endl;

        prepare(n*2+2,0,n*2+1);
        for (int i=1; i<=n; i++)
        {
            if (i==1||i==n)
            {
                addedge(i,i+n,OO);
                if (f[i]==1) addedge(src,i,OO);
                if (f[i]==s) addedge(i+n,dest,OO);
            }
            else
            {
                addedge(i,i+n,1);
                if (f[i]==1) addedge(src,i,1);
                if (f[i]==s) addedge(i+n,dest,1);
            }
            for (int j=1; j<i; j++)
            {
                if (f[j]+1==f[i]&&a[i]>a[j]) addedge(j+n,i,1);
            }
        }
        int ans2=Dinic_flow();
        if (ans2>OO) cout<<ans1<<endl;
        else cout<<ans2<<endl;
    }
    return 0;
}
