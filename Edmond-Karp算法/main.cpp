#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF=1e9;
const int maxn=111;//最大点个数
int map[maxn][maxn],n,pre[maxn];//map邻接矩阵,n点数，p前驱数组
bool EK_bfs(int start,int end);

bool EK_bfs(int start,int end)
{
    queue<int>que;//广搜队列
    bool visit[maxn];//标记数组
    memset(visit,0,sizeof(visit));
    memset(pre,-1,sizeof(pre));
    que.push(start);
    visit[start]=true;
    while (!que.empty())
    {
        int u=que.front();
        if (u==end) return true;//增广路找到
        que.pop();
        for (int v=1;v<=n;v++)
        {
            if (map[u][v]&&!visit[v])//边容量非零且增广点未标记
            {
                visit[v]=true;
                pre[v]=u;//记录前驱
                que.push(v);//入队
            }
        }
    }
    return false;
}

int EK_max_flow(int start,int end)
{
    int u,flow_ans=0,mn;//初始化最大流为0
    while (EK_bfs(start,end))//当增广成功
    {
        mn=INF;
        u=end;
        while (pre[u]!=-1)//寻找瓶颈边并记录容量
        {
            mn=min(mn,map[ pre[u] ][ u ]);
            u=pre[u];
        }
        flow_ans+=mn;//累加进最大流
        u=end;
        while (pre[u]!=-1)//修改路径上的边容量
        {
            map[ pre[u] ][ u ]-=mn;
            map[ u ][ pre[u] ]+=mn;
            u=pre[u];
        }
    }
    return flow_ans;
}


int main()
{
    return 0;
}
