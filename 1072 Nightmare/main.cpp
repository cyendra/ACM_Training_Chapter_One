#include <iostream>
#include <cstring>
#include <cstdio>
#define OO 999999

using namespace std;

typedef struct
{
    int x;
    int y;
    int step;
    int boom;
}POINT;

int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
int map[10][10];
int v[10][10];
int n,m,T;
int bgx,bgy,edx,edy;
int ans;
bool ok;

void dfs(POINT p);

void dfs(POINT p)
{
    int rx=-1,ry=-1;
    POINT tmp;
    if ( p.boom<=0 )
    {
        return;
    }
    if ( p.step>=ans )
    {
        return;
    }
    if ( p.x==edx && p.y==edy )
    {
        if ( p.step<ans )
        {
            ans=p.step;
            ok=true;
        }
    }
    if ( map[p.x][p.y]==4 )
    {
        p.boom=6;
        //rx=p.x;
        //ry=p.y;
        //map[rx][ry]=1;
    }
    if ( p.boom>v[p.x][p.y] )
    {
        v[p.x][p.y]=p.boom;
        rx=p.x;
        ry=p.y;
    }
    tmp.step=p.step;
    tmp.boom=p.boom;
    tmp.step++;
    tmp.boom--;
    for (int i=0;i<4;i++)
    {
        tmp.x=p.x+direct[i][0];
        tmp.y=p.y+direct[i][1];
        if ( tmp.x>=0&&tmp.x<n&&tmp.y>=0&&tmp.y<m&&map[tmp.x][tmp.y]!=0&&tmp.boom>v[tmp.x][tmp.y] ) dfs(tmp);
    }
    if (rx!=-1&&ry!=-1)
    {
        v[rx][ry]=0;
    }

}

int main()
{
    POINT tp;
    scanf("%d",&T);
    for (int loop=0; loop<T; loop++)
    {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                scanf("%d",&map[i][j]);
                v[i][j]=0;
                if ( map[i][j]==2 )
                {
                    bgx=i;
                    bgy=j;
                }
                if ( map[i][j]==3 )
                {
                    edx=i;
                    edy=j;
                }
            }
        }
        tp.x=bgx;
        tp.y=bgy;
        tp.step=0;
        tp.boom=6;
        ans=OO;
        ok=false;
        dfs(tp);
        if ( ok )
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
