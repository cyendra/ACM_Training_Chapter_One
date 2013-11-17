#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//定义变量与常量
const int V = 1005;
int g[V][V];
int stk[V];
int num[V];
int id[V];
int low[V],pre[V];
int cnt,scnt,stop;
int m;
//定义函数
void addedge(int a,int b);
void dfs(int v);
void tarjan();

void addedge(int a,int b)
{
    if (g[a][b]!=0)
    {
        g[a][b]=0;
    }
    else
    {
        g[a][b]=1;
    }
}

void tarjan()
{
    stop=0;
    cnt=0;
    scnt=0;
    for (int i=0;i<=2*m;i++)
    {
        if (pre[i]==-1)
        {
            dfs(i);
        }
    }
}

void dfs(int v)
{
    int t;
    pre[v]=cnt;
    low[v]=cnt;
    int minc=cnt;
    cnt++;
    stk[stop]=v;
    stop++;
    for (int i=0;i<=2*m;i++)
    {
        if (g[v][i]!=0)
        {
            if (pre[i]==-1)
            {
                dfs(i);
            }
            if (low[i]<minc)
            {
                minc=low[i];
            }
        }
    }
    if (minc<low[v])
    {
        low[v]=minc;
        return;
    }
    do
    {
        stop--;
        t=stk[stop];
        id[t]=scnt;
        low[t]=2*m+1;
    }
    while(t!=v);
    scnt++;
}
//主函数
int main()
{
    int n;
    while (scanf("%d%d",&n,&m))
    {
        memset(g,0,sizeof(g));
        memset(pre,-1,sizeof(pre));
        memset(num,0,sizeof(num));
        memset(low,-1,sizeof(low));
        for (int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if (a>b)
            {
                swap(a,b);
            }
            num[a]=i+1;
            num[b]=i+1;
            for (int j=a+1;j<b;j++)
            {
                if (num[j]!=0)
                {
                    addedge(2*i+1,2*j);
                    addedge(2*i+2,2*j-1);
                }
            }
        }
        tarjan();
        bool ans=true;
        for (int i=0;i<m;i++)
        {
            if (id[2*i]==id[2*i+1])
            {
                ans=false;
            }
        }
        if (ans==true)
        {
            printf("panda is telling the truth...\n");
        }
        else
        {
            printf("the evil panda is lying again");
        }
    }
    return 0;
}
