#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

const int INF=1e9+7;
const int maxm=111111;
const int maxn=11111;
const int direct[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };

struct EDGENODE{
    int to;
    int next;
    int w;
};

class CSPFA{
private:
    EDGENODE edges[maxm];
    int head[maxn],edge,node;
    bool visit[maxn];
    int outque[maxn];
    queue<int>que;
public:
    int dist[maxn];
    void addedge(int u,int v,int c){
        edges[edge].w=c,edges[edge].to=v,edges[edge].next=head[u],head[u]=edge++;
        //edges[edge].w=c,edges[edge].to=u,edges[edge].next=head[v],head[v]=edge++;
    }
    void init(int n){
        memset(head,-1,sizeof(head));
        edge=0;
        node=n;
    }
    bool SPFA(int src)
    {
        int top;
        for (int i=0;i<=node;i++) dist[i]=INF;
        memset(visit,0,sizeof(visit));
        memset(outque,0,sizeof(outque));
        while (!que.empty()) que.pop();
        que.push(src);
        visit[src]=true;
        dist[src]=0;
        while (!que.empty()){
            top=que.front();
            que.pop();
            visit[top]=false;
            outque[top]++;
            if (outque[top]>node) return false;
            for (int k=head[top];k!=-1;k=edges[k].next)
            {
                if ( dist[edges[k].to]==INF||dist[edges[k].to]>dist[top]+edges[k].w )
                {
                    dist[edges[k].to]=dist[top]+edges[k].w;
                    if (!visit[edges[k].to])
                    {
                        visit[edges[k].to]=true;
                        que.push(edges[k].to);
                    }
                }
            }
        }
        return true;
    }
    int max_short_path(int u)
    {
        int ans=0;
        SPFA(u);
        for (int i=0;i<node;i++) ans=max(ans,dist[i]);
        return ans;
    }
};


class GameOnABoard{
private:
    CSPFA sol;
    int n,m;
    bool xycheck(int x,int y){
        if (x>=0&&x<n&&y>=0&&y<m) return true;
        return false;
    }
public:
    int optimalChoice(vector<string> cost)
    {
        int ans;
        n=cost.size();
        m=cost[0].size();
        sol.init(n*m);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                for (int k=0;k<4;k++)
                {
                    int x=i+direct[k][0];
                    int y=j+direct[k][1];
                    if (xycheck(x,y)) sol.addedge(i*m+j,x*m+y,cost[x][y]-'0');
                }
            }
        }
        ans=INF;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                int t=cost[i][j]-'0';
                ans=min(ans,sol.max_short_path(i*m+j)+t);
            }
        }
        return ans;
    }
};

int main()
{
    GameOnABoard test;
    int n;
    vector<string> cost;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        cost.push_back(s);
    }
    cout<<test.optimalChoice(cost)<<endl;
    return 0;
}
