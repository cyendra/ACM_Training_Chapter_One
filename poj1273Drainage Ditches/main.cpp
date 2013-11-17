#include <iostream>
#include <cstring>
#include <queue>
#define OO 10000001
using namespace std;

int a[300][300];
int f[300][300];
int pre[300];
int flow[300];
int n,m;
int ans;
queue<int>que;

int BFS(int src,int des);
int maxFlow(int src,int des);

int maxFlow(int src,int des)
{
    int ret=0;
    int d=0;
    while ( (d=BFS(src,des))!=-1 )
    {
        int p=des;
        while (p!=src)
        {
            int last=pre[p];
            f[last][p]-=d;
            f[p][last]+=d;
            p=last;
        }
        ret+=d;
    }
    return ret;
}

int BFS(int src,int des)
{
    while (!que.empty()) que.pop();
    for (int i=1;i<=n;i++) pre[i]=-1;
    pre[src]=0;
    flow[src]=OO;
    que.push(src);
    while (!que.empty())
    {
        int p=que.front();
        que.pop();
        if (p==des) break;
        for (int i=1;i<=n;i++)
        {
            if (i!=src&&pre[i]==-1&&f[p][i]>0)
            {
                pre[i]=p;
                flow[i]=min( f[p][i] , flow[p] );
                que.push(i);
            }
        }
    }
    if (pre[des]==-1) return -1;
    else return flow[des];
}

int main()
{
    int x,y,z;
    while (cin>>m>>n)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(flow,0,sizeof(flow));
        ans=0;
        for (int i=1;i<=m;i++)
        {
            cin>>x>>y>>z;
            //a[x][y]=z;
            if (x==y) continue;
            f[x][y]+=z;
        }
        ans=maxFlow(1,n);
        cout<<ans<<endl;
    }
    return 0;
}

/*
bool findway(int p);
void build();

bool findway(int p)
{
    if (p==n) return true;
    for (int i=1;i<=n;i++)
    {
        if (pre[i]==-1&&(a[p][i]-f[p][i]>0||f[i][p]>0))
        {
            pre[i]=p;
            if (findway(i)) return true;
        }
    }
    return false;
}

void build()
{
    int i,d;
    d=OO;
    i=n;
    while (pre[i]!=0)
    {

        if (a[pre[i]][i]>0) d=min(d,a[pre[i]][i]-f[pre[i]][i]);
        if (a[i][pre[i]]>0) d=min(d,f[i][pre[i]]);
        i=pre[i];
    }
    i=n;
    while (pre[i]!=0)
    {
        if (a[pre[i]][i]>0) f[pre[i]][i]+=d;
        if (a[i][pre[i]]>0) f[i][pre[i]]-=d;
        i=pre[i];
    }
    ans+=d;
}
*/
