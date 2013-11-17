#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int f[2111][5][55];
int a[2111][5];

int T,W;

int dfs(int time,int tree,int jump)
{
    if (f[time][tree][jump]!=-1) return f[time][tree][jump];
    int ret=0;
    if (time<T)
    {
        ret=dfs(time+1,tree,jump);
        if (jump>0)
        {
            if (tree==1)
            {
                ret=max( ret, dfs(time+1,2,jump-1) );
            }
            else if (tree==2)
            {
                ret=max( ret, dfs(time+1,1,jump-1) );
            }
        }
    }
    f[time][tree][jump]=ret+a[time][tree];
    return f[time][tree][jump];
}

int main()
{

    while (~scanf("%d%d",&T,&W))
    {
        memset(a,0,sizeof(a));
        memset(f,-1,sizeof(f));
        for (int i=1;i<=T;i++)
        {
            int t;
            scanf("%d",&t);
            a[i][t]=1;
        }
        int ans=max(dfs(0,1,W), dfs(0,2,W));
        printf("%d\n",ans);
    }
    return 0;
}

