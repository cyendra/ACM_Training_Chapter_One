#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef struct{
    int x;
    int y;
}POINT;

int direct[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };

int a[60][60];
int g[60][60];
long long int f[60][60];
int n;
long long int ans;
__int64 dfs(POINT p);

__int64 dfs(POINT p)
{
    POINT t;
    if ( f[p.x][p.y]!=-1 )
    {
        return f[p.x][p.y];
    }
    if (p.x==n&&p.y==n)
    {
        return 1;
    }
    f[p.x][p.y]=0;
    for (int i=0;i<4;i++)
    {
        t.x=p.x+direct[i][0];
        t.y=p.y+direct[i][1];
        if ( t.x>=1&&t.x<=n&&t.y>=1&&t.y<=n&&g[t.x][t.y]<g[p.x][p.y] )
        {
            f[p.x][p.y]+=dfs(t);
        }
    }
    return f[p.x][p.y];
}

/*
void bfs(int x,int y)
{
 queue<node>q;
 node cur,next;
 cur.x=x;
 cur.y=y;
 cur.time=map[n][n];
 hust[x][y]=map[n][n];
 q.push(cur);
 while(!q.empty())
 {
  int i;
  cur=q.front();
  q.pop();
  for(i=0;i<4;i++)
  {
   next.x=cur.x+str[i][0];
   next.y=cur.y+str[i][1];
   if(next.x<=0||next.y<=0||next.x>n||next.y>n)
    continue;
   next.time=cur.time+map[next.x][next.y];
   if(hust[next.x][next.y]==0||next.time<hust[next.x][next.y])
   {
    hust[next.x][next.y]=next.time;
    q.push(next);
   }
  }
 }
}
*/

int main()
{
    POINT bg;
    while ( scanf("%d",&n)!=EOF )
    {
        memset(a,0,sizeof(a));
        memset(g,0,sizeof(g));
        memset(f,-1,sizeof(f));

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
//WA
        for (int i=n;i>=1;i--)
        {
            for (int j=n;j>=1;j--)
            {
                if ( i==n && j==n )
                {
                    g[i][j]=a[i][j];
                }
                else if (i==n && j!=n)
                {
                    g[i][j]=a[i][j]+g[i][j+1];
                }
                else if ( i!=n && j==n )
                {
                    g[i][j]=a[i][j]+g[i+1][j];
                }
                else
                {
                    g[i][j]=min( a[i][j]+g[i+1][j] , a[i][j]+g[i][j+1] );
                }
            }
        }
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if ( i==1 && j==1 )
                {
                    f[i][j]=1;
                }
                if ( i!=1 && j==1 )
                {
                    if ( g[i][j]<g[i-1][j] ) f[i][j]+=f[i-1][j];
                }
                else if ( i==1 && j!=1 )
                {
                    if ( g[i][j]<g[i][j-1] ) f[i][j]+=f[i][j-1];
                }
                else
                {
                    if ( g[i][j]<g[i-1][j] ) f[i][j]+=f[i-1][j];
                    if ( g[i][j]<g[i][j-1] ) f[i][j]+=f[i][j-1];
                }
            }
        }
        */
        ans=0;
        bg.x=1;
        bg.y=1;
        printf("%I64d\n",dfs(bg));
    }
    return 0;
}
