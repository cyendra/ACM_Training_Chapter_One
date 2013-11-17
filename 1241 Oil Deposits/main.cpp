#include <iostream>
#include <cstdio>
#include <queue>
#define N 110

using namespace std;
typedef struct{
    short x;
    short y;
}POINT;

queue<POINT>que;

int direct[8][2]={ {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };

char map[N][N];
int v[N][N];
int ans;
int n,m;

POINT p,tmp;

void dfs(POINT t)
{
    POINT pt;
    v[t.x][t.y]=ans;
    for (int i=0;i<8;i++)
    {
        pt.x=t.x+direct[i][0];
        pt.y=t.y+direct[i][1];
        if (pt.x>=0&&pt.x<m&&pt.y>=0&&pt.y<n&&v[pt.x][pt.y]==0&&map[pt.x][pt.y]=='@' )
        {
            dfs(pt);
        }
    }

}

int main()
{
    while ( scanf("%d",&m)!=EOF && m!=0 )
    {
        scanf("%d",&n);
        for (int i=0;i<m;i++)
        {
            scanf("%s",map[i]);
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                v[i][j]=0;
            }
        }
        ans=0;
        while (!que.empty()) que.pop();
        for (int li=0;li<m;li++)
        {
            for (int lj=0;lj<n;lj++)
            {
                if (v[li][lj]==0 && map[li][lj]=='@' )
                {
                    ans++;
                    //while (!que.empty()) que.pop();
                    p.x=li;
                    p.y=lj;
                    dfs(p);
                    //que.push(p);
                    /*
                    while (!que.empty())
                    {
                        tmp=que.front();
                        que.pop();
                        v[tmp.x][tmp.y]=ans;
                        for (int i=0;i<8;i++)
                        {
                            p.x=tmp.x+direct[i][0];
                            p.y=tmp.y+direct[i][1];
                            if ( p.x>=0&&p.x<m&&p.y>=0&&p.y<n&&v[p.x][p.y]==0&&map[p.x][p.y]=='@' )
                            {
                                que.push(p);
                            }
                        }
                    }
                    */
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
