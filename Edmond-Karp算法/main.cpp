#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int INF=1e9;
const int maxn=111;//�������
int map[maxn][maxn],n,pre[maxn];//map�ڽӾ���,n������pǰ������
bool EK_bfs(int start,int end);

bool EK_bfs(int start,int end)
{
    queue<int>que;//���Ѷ���
    bool visit[maxn];//�������
    memset(visit,0,sizeof(visit));
    memset(pre,-1,sizeof(pre));
    que.push(start);
    visit[start]=true;
    while (!que.empty())
    {
        int u=que.front();
        if (u==end) return true;//����·�ҵ�
        que.pop();
        for (int v=1;v<=n;v++)
        {
            if (map[u][v]&&!visit[v])//�����������������δ���
            {
                visit[v]=true;
                pre[v]=u;//��¼ǰ��
                que.push(v);//���
            }
        }
    }
    return false;
}

int EK_max_flow(int start,int end)
{
    int u,flow_ans=0,mn;//��ʼ�������Ϊ0
    while (EK_bfs(start,end))//������ɹ�
    {
        mn=INF;
        u=end;
        while (pre[u]!=-1)//Ѱ��ƿ���߲���¼����
        {
            mn=min(mn,map[ pre[u] ][ u ]);
            u=pre[u];
        }
        flow_ans+=mn;//�ۼӽ������
        u=end;
        while (pre[u]!=-1)//�޸�·���ϵı�����
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
