#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <cstdio>
#define SIZE 300
using namespace std;

bool dfs(int x);

vector<int>list[SIZE];
stack<int>stk;

int size_x,size_y;
bool visit[SIZE];
int X[SIZE];
int Y[SIZE];

bool dfs(int x)
{
    vector<int>::iterator it;
    stk.push(x);
    for (it=list[x].begin();it<list[x].end();it++)
    {
        if ( visit[*it]==false )
        {
            visit[*it]=true;
            stk.push(*it);
            if ( Y[*it]==0 || dfs(Y[*it])==true )
            {
                return true;
            }
            else
            {
                stk.pop();
            }
        }
    }
    stk.pop();
    return false;
}

int main()
{
    int n,t,tx,ty;
    while ( scanf("%d",&size_x)!=EOF && size_x!=0 )
    {
        scanf("%d%d",&size_y,&n);
        //init
        for (int i=1; i<=size_x; i++)
        {
            list[i].clear();
        }
        memset(X,0,sizeof(X));
        memset(Y,0,sizeof(Y));
        //input
        for (int i=0; i<n; i++)
        {
            scanf("%d%d%d",&t,&tx,&ty);
            if (tx==0||ty==0) continue;
            list[tx].push_back(ty);
        }
        //solve
        int top;
        for (int i=1; i<=size_x; i++)
        {
            while ( !stk.empty() ) stk.pop();
            memset(visit,false,sizeof(visit));
            if (dfs(i)==true)
            {
                while (!stk.empty())
                {
                    top=stk.top();
                    stk.pop();
                    Y[top]=stk.top();
                    X[stk.top()]=top;
                    stk.pop();
                }
            }
        }
        //output
        int ans=0;
        for (int i=1;i<=size_x;i++)
        {
            if ( X[i]>0 ) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
