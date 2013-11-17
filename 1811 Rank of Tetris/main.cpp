#include <iostream>
#include <cstdio>
#include <queue>
#define N 20020

using namespace std;

//queue<int>que;

int L[N],R[N],P[N],deg[N],n,m;
char O[N];

struct edge{
    int v;
    edge *next;
}*e[N];

int find(int x)
{
    while (P[x]!=x)
    {
        x=P[x];
    }
    return x;
}

void addedge(int u,int w)
{
    edge * ptr;
    ptr=new edge;
    ptr->v=w;
    ptr->next=e[u];
    e[u]=ptr;
}

void init()
{
    for (int i=0;i<n;i++)
    {
        P[i]=i;
        e[i]=NULL;
        deg[i]=0;
    }
}

int main()
{
    bool flag;
    int num;
    bool stan;
    while (scanf("%d%d",&n,&m)==2)
    {
        flag=true;
        num=n;
        init();
        //并查集
        for (int i=0;i<m;i++)
        {
            scanf("%d %c %d",&L[i],&O[i],&R[i]);
            if (O[i]=='=')
            {
                int X=find(L[i]);
                int Y=find(R[i]);
                if (X!=Y)
                {
                    P[X]=Y;
                    num--;
                }
            }
        }
        //建图
        for (int i=0;i<m;i++)
        {
            if (O[i]=='=')
            {
                continue;
            }
            int X=find(L[i]);
            int Y=find(R[i]);
            if (X==Y)
            {
                flag=false;
            }
            if (O[i]=='>')
            {
                addedge(X,Y);
                deg[Y]++;
            }
            else
            {
                addedge(Y,X);
                deg[X]++;
            }
        }
        //拓扑
        //while (!que.empty()) que.pop();
        queue<int>que;
        for (int i=0;i<n;i++)
        {
            if (deg[i]==0 && find(i)==i)
            {
                que.push(i);
            }
        }
        stan=false;
        while (!que.empty())
        {
            if (que.size()>1)
            {
                stan=true;
            }
            int t=que.front();
            que.pop();
            num--;
            for (edge* p=e[t];p;p=p->next)
            {
                if (--deg[p->v]==0)
                {
                    que.push(p->v);
                }
            }
        }
        if (num>1 || flag==false)
        {
            printf("CONFLICT\n");
        }
        else if (stan==true)
        {
            printf("UNCERTAIN\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    return 0;
}
