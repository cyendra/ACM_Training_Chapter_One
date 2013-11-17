#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct
{
    int x;
    int y;
} POINT;

int mov[4][2]= { {1,0},{0,1},{-1,0},{0,-1} }; //1下 2右 3上 4左
//int chr[11][4]={ {3,4,-1,-1},{2,3,-1,-1},{1,4,-1,-1},{1,2,-1,-1},{1,3,-1,-1},{2,4,-1,-1},{2,3,4,-1},{1,3,4,-1},{1,2,4,-1},{1,2,3,-1},{1,2,3,4} };
int direct[11][4]= { {0,0,1,1},{0,1,1,0},{1,0,0,1},{1,1,0,0},{1,0,1,0},{0,1,0,1},{0,1,1,1},{1,0,1,1},{1,1,0,1},{1,1,1,0},{1,1,1,1} };
int ud[4]= {2,3,0,1};

char chrmap[60][60];
int map[60][60];
int v[60][60];
int n,m;
int ans;
POINT p,tmp;
int mtype;

queue<POINT>que;

int main()
{
    while (scanf("%d%d",&m,&n)!=EOF)
    {
        if (m==-1&&n==-1) break;
        for (int i=0; i<m; i++)
        {
            scanf("%s",chrmap[i]);
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                map[i][j]=chrmap[i][j]-'A';
                v[i][j]=0;
            }
        }
        ans=0;
        //初始化输入完毕

        while (!que.empty()) que.pop();//清队列

        for (int li=0; li<m; li++)
        {
            for (int lj=0; lj<n; lj++)
            {
                if (v[li][lj]==0)
                {
                    while (!que.empty()) que.pop();//清队列准备入队
                    ans++;//答案加一
                    //入队染色
                    p.x=li;
                    p.y=lj;
                    que.push(p);
                    while ( !que.empty() )
                    {
                        tmp=que.front();
                        que.pop();
                        v[tmp.x][tmp.y]=ans;
                        mtype=map[tmp.x][tmp.y];
                        for (int i=0; i<4; i++)
                            if ( direct[mtype][i]==1 )
                            {
                                p.x=tmp.x+mov[i][0];
                                p.y=tmp.y+mov[i][1];
                                if ( p.x>=0&&p.x<m&&p.y>=0&&p.y<n&&v[p.x][p.y]==0 &&direct[ map[p.x][p.y] ][ud[i]]!=0 )
                                {
                                    que.push(p);
                                }
                            }
                    }
                    //染色结束
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
