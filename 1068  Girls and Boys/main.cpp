#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#define SIZE 3000
using namespace std;

void solve();
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
    for ( it=list[x].begin(); it<list[x].end(); it++ )
    {
        if ( !visit[ *it ] )
        {
            visit[ *it ]=true;
            stk.push( *it );
            if ( Y[ *it ]==-1 || dfs( Y[ *it ] ) )
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

void solve()
{
    int top;
    for (int i=0; i<size_x; i++)
    {
        while (!stk.empty()) stk.pop();
        memset(visit,false,sizeof(visit));
        if ( dfs(i) )
        {
            while ( !stk.empty() )
            {
                top=stk.top();
                stk.pop();
                Y[top]=stk.top();
                X[stk.top()]=top;
                stk.pop();
            }
        }
    }
}


int main()
{
    int n,t,tn,tx,ty;
    while ( scanf("%d",&n)!=EOF )
    {
        size_x=size_y=n;
        for (int i=0;i<size_x;i++)
        {
            list[i].clear();
        }
        memset(X,-1,sizeof(X));
        memset(Y,-1,sizeof(Y));
        for (int i=0;i<n;i++)
        {
            scanf("%d: (%d) ",&tx,&t);
            for (int j=0;j<t;j++)
            {
                scanf("%d",&ty);
                list[tx].push_back(ty);
            }
        }
        solve();
        int ans=0;
        for (int i=0;i<size_x;i++)
        {
            if ( X[i]>-1 ) ans++;
        }
        //printf("%d\n",ans);
        printf("%d\n",n-ans/2);
    }
    return 0;
}
