#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <stack>
#define SIZE 300
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
    for ( it=list[x].begin();it<list[x].end();it++ )
    {
        if ( !visit[ *it ] )
        {
            visit[ *it ]=true;
            stk.push( *it );
            if ( Y[ *it ]==0 || dfs( Y[ *it ] ) )
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
    for (int i=1;i<=size_x;i++)
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
    int LN,n,m,tx,ty;
    scanf("%d",&LN);
    for (int loop=0;loop<LN;loop++)
    {
        scanf("%d%d",&n,&m);
        //init
        for (int i=1;i<=n;i++)
        {
            list[i].clear();
        }
        memset(X,0,sizeof(X));
        memset(Y,0,sizeof(Y));
        //input
        size_x=n;
        size_y=n;
        for (int i=0;i<m;i++)
        {
            scanf("%d%d",&tx,&ty);
            list[tx].push_back(ty);
        }
        //solve
        solve();
        //output
        int ans=0;
        for (int i=1;i<=size_x;i++)
        {
            if ( X[i]>0 ) ans++;
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
