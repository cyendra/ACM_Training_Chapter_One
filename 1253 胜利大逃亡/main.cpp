#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

typedef struct
{
    char x;
    char y;
    char z;
    short step;
} POINT;

queue<POINT>que;

int direct[6][3]= { {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };
int map[60][60][60];
bool visit[60][60][60];
POINT p,tmp;
int A,B,C,T;
int ans;

int main()
{
    int K;
    scanf("%d",&K);
    for (int loop=1; loop<=K; loop++)
    {
        scanf("%d%d%d%d",&A,&B,&C,&T);
        for (int i=0; i<A; i++)
        {
            for (int j=0; j<B; j++)
            {
                for (int k=0; k<C; k++)
                {
                    scanf("%d",&map[i][j][k]);
                    visit[i][j][k]=false;
                }
            }
        }
        if ( A+B+C-3>T )
        {
            printf("-1\n");
            continue;
        }
        if ( map[A-1][B-1][C-1]==1 )
        {
            printf("-1\n");
            continue;
        }
        p.x=0;
        p.y=0;
        p.z=0;
        p.step=0;
        ans=-1;
        visit[0][0][0]=true;
        while (!que.empty()) que.pop();
        que.push(p);
        while ( !que.empty() )
        {
            tmp=que.front();
            que.pop();
            //if ( map[tmp.z][tmp.x][tmp.y]==1&&tmp.z!=0&&tmp.x!=0&&tmp.y!=0 ) continue;
            if ( tmp.z==A-1 && tmp.x==B-1 && tmp.y==C-1 )
            {
                ans=tmp.step;
                break;
            }
            for (int i=0; i<6; i++)
            {
                p.z=tmp.z+direct[i][0];
                p.x=tmp.x+direct[i][1];
                p.y=tmp.y+direct[i][2];
                p.step=tmp.step+1;
                if ( p.step>T ) continue;
                if ( p.z>=0&&p.z<A&&p.x>=0&&p.x<B&&p.y>=0&&p.y<C&&map[p.z][p.x][p.y]==0&&visit[p.z][p.x][p.y]==false )
                {
                    visit[p.z][p.x][p.y]=true;
                    que.push(p);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
