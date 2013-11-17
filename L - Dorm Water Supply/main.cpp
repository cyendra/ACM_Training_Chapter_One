#include <iostream>
#include <cstring>

using namespace std;

struct ANS{
    int u;
    int v;
    int d;
}ans[1111];

int cnt;
int n,m;
int next[1111]={0};
int cost[1111]={0};
int pre[1111]={0};
bool v[1111]={0};

void dfs(int i);

void dfs(int i,int flow)
{
    v[i]=true;
    if (next[i]==0)
    {
        ans[cnt].d=flow;
        ans[cnt].v=i;
        return;
    }
    int j=next[i];
    if (cost[j]<flow&&cost[j]!=0)
    {
        dfs(j,cost[j]);
    }
    else
    {
        dfs(j,flow);
    }
}

int main()
{
    cnt=0;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int a,b,k;
        cin>>a>>b>>k;
        next[a]=b;
        pre[b]=a;
        cost[a]=k;
    }
    for (int i=1;i<=n;i++)
    {
        if (!v[i]&&pre[i]==0&&next[i]!=0)
        {
            ans[cnt].u=i;
            dfs(i,cost[i]);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for (int i=0;i<cnt;i++)
    {
        cout<<ans[i].u<<" "<<ans[i].v<<" "<<ans[i].d<<endl;
    }
    return 0;
}
