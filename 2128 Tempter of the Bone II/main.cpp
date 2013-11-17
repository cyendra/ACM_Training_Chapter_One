/*
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cctype>

using namespace std;
int n,m;
struct HERO{
    int x;
    int y;
    int step;
    int boom;
    int map[9][9];
    bool logic( int x, int y )
    {
        if( x >= 0 && x < n && y >= 0 && y < m ) return true;
        return false;
    }
    bool operator < ( HERO t ) const
    {
        return step < t.step;
    }
}p;

char a[9][9];
int f[9][9];
queue<HERO> que;
int bgx,bgy;
int x,y,bo,st;
char str[10];
HERO pt;
int ans;
int point[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if ((n==0)&&(m==0))
        {
            break;
        }
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                f[i][j]=0;
            }
        }
        ans=10000;
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            for (int j=0;j<m;j++)
            {
                a[i][j]=str[j];
                if (a[i][j]=='S')
                {
                    bgx=i;
                    bgy=j;
                }
            }
        }
        //检验

        p.x=bgx;
        p.y=bgy;
        p.step=0;
        p.boom=0;
        memset(p.map,-1,sizeof(p.map));

        while (!que.empty())
        {
            que.pop();
        }
        //初始化完成
        que.push(p);
        while ( !que.empty() )
        {
            pt=que.front();
            que.pop();
            if (ans!=10000 && pt.step>=ans)
            {
                continue;
            }
            for (int i=0;i<4;i++)
            {
                x=pt.x+point[i][0];
                y=pt.y+point[i][1];
                st=pt.step;
                bo=-1;
                if (p.logic(x,y))
                {
                    if (a[x][y]=='D')
                    {
                        if (ans>=st+1)
                        {
                            ans=st+1;
                        }
                        continue;
                    }
                    else if (pt.map[x][y]>-1||a[x][y]=='.')
                    {
                        st++;
                        bo=pt.boom;
                    }
                    else if (a[x][y]=='X'&&pt.boom>0)
                    {
                        st+=2;
                        bo=pt.boom-1;
                    }
                    else if ( isdigit(a[x][y]) )
                    {
                        st++;
                        bo=pt.boom+(a[x][y]-'0');
                    }
                    if (bo>pt.map[x][y])
                    {
                        p.x=x;
                        p.y=y;
                        p.step=st;
                        p.boom=bo;
                        memcpy(p.map,pt.map,sizeof(p.map));
                        p.map[x][y]=bo;
                        que.push(p);
                    }
                }
            }
        }
        if (ans!=10000)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
*/

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cctype>
#define INF 100000
using namespace std;

int N, M, ans, sx, sy;

char map[10][10];

int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

struct Node
{
    int x, y, vs, step;
    int mvs[8][8];
    bool logic( int tx, int ty )
    {
        if( tx >= 0 && tx < N && ty >= 0 && ty < M )
            return true;
        return false;
    }
    bool operator < ( Node t ) const
    {
        return step < t.step;
    }
} info;


bool BFS(  )
{
    info.x = sx, info.y = sy;
    info.step= 0, info.vs = 0;
    memset( info.mvs, -1, sizeof( info.mvs ) ); // 初始化为-1
    info.mvs[sx][sy] = 0;
    queue<Node>q;
    q.push( info );
    while( !q.empty() )
    {
        Node pos = q.front();
        q.pop();
        if( ans != INF && pos.step >= ans )
            continue;
        for( int i = 0; i < 4; ++i )
        {
            int tx = pos.x + dir[i][0], ty = pos.y + dir[i][1];
            int tt = pos.step, tvs = -1;
            if( info.logic( tx, ty ) )
            {
                if( map[tx][ty] == 'D' )
                {
                    ans = ans < tt + 1 ? ans : tt + 1;
                    continue;
                }
                else if( pos.mvs[tx][ty] > -1 || map[tx][ty] == '.' ) // 该点已经走过
                    tt += 1, tvs = pos.vs;
                else if( map[tx][ty] == 'X' && pos.vs > 0 )
                {
                    tt += 2;
                    tvs = pos.vs - 1;
                }
                else if( isdigit( map[tx][ty] ) )
                {
                    tt += 1;
                    tvs = pos.vs + ( map[tx][ty] - '0' );
                }
                if( tvs > pos.mvs[tx][ty] )
                {
                    info.x = tx, info.y = ty, info.step = tt;
                    info.vs = tvs;
                    memcpy( info.mvs, pos.mvs, sizeof( info.mvs ) );
                    info.mvs[tx][ty] = tvs;
                    q.push( info );
                }
            }
        }
    }
    if( ans == INF )
        return false;
    else
        return true;
}
int main()
{
    while( scanf( "%d %d", &N, &M ), N | M )
    {
        for( int i = 0; i < N; ++i )
        {
            scanf( "%s", map[i] );
            for( int j = 0; j < M; ++j )
            {
                if( map[i][j] == 'S' )
                    sx = i, sy = j;
            }
        }
        ans = INF;
        printf( BFS() ? "%d\n" : "-1\n" , ans );
    }
    return 0;
}
