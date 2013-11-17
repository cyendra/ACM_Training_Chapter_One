#include <iostream>
#include <cstdio>
#include <queue>

typedef struct{
    int c;
    int x;
    int y;
    int tm;
}HEROPOINT;

//定义变量
using namespace std;
int n,m,t;
int sx,sy,sc,px,py,pc;
char a[2][11][11];
int f[2][11][11];
int mov[4][2]={ {-1,0},{0,-1},{1,0},{0,1} };
char str[20];
bool ok;
int x,y,c,nx,ny,nc;
HEROPOINT p,newp;
queue<HEROPOINT>que;

//主函数
int main()
{
    int c;
    scanf("%d",&c);
    for (int i=0;i<c;i++)
    {
        //读入数据
        sx=0;
        sy=0;
        sc=0;
        ok=false;

        scanf("%d%d%d",&n,&m,&t);
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                    cin>>a[i][j][k];
                }
            }
        }
        /*
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            for (int j=0;j<m;j++)
            {
                a[0][i][j]=str[j];
            }
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s",str);
            for (int j=0;j<m;j++)
            {
                a[1][i][j]=str[j];
            }
        }
        */
        //处理特殊情况
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                //寻找终点
                if (a[0][i][j]=='P')
                {
                    px=i;
                    py=j;
                    pc=0;
                }
                if (a[1][i][j]=='P')
                {
                    px=i;
                    py=j;
                    pc=1;
                }
                //寻找传送点
                if ( (a[0][i][j]=='#') && (a[1][i][j]=='#') )
                {
                    a[0][i][j]='*';
                    a[1][i][j]='*';
                }
                if ( (a[0][i][j]=='#') && (a[1][i][j]=='*') )
                {
                    a[0][i][j]='*';
                }
                if ( (a[1][i][j]=='#') && (a[0][i][j]=='*') )
                {
                    a[1][i][j]='*';
                }
            }
        }

        //检验
        /*
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                printf("%c",a[0][i][j]);
            }
            printf("\n");
        }
        */

        while(!que.empty()) que.pop();

        //广度优先搜索
        for (int i=0;i<11;i++)
        {
            for (int j=0;j<11;j++)
            {
                f[0][i][j]=1000;
                f[1][i][j]=1000;
            }
        }
        f[0][0][0]=0;
        p.c=sc;
        p.x=sx;
        p.y=sy;
        p.tm=0;
        que.push(p);
        ok=false;
        while ((!que.empty()) && (ok!=true) )//!myqueue.empty()
        {
            p=que.front();
            que.pop();
            //移动逻辑判断
            for (int i=0;i<4;i++)
            {
                newp=p;
                newp.x+=mov[i][0];
                newp.y+=mov[i][1];
                newp.tm++;
                if ( (newp.x<0) || (newp.x>=n) || (newp.y<0) || (newp.y>=m) || (newp.tm>t) )
                {
                    continue;
                }
                if (a[newp.c][newp.x][newp.y]=='*')
                {
                    continue;
                }
                if (newp.tm>=f[newp.c][newp.x][newp.y])
                {
                    continue;
                }
                f[newp.c][newp.x][newp.y]=newp.tm;
                if (a[newp.c][newp.x][newp.y]=='#')
                {
                    newp.c=(newp.c+1)%2;
                    if (newp.tm>=f[newp.c][newp.x][newp.y])
                    {
                        continue;
                    }
                    f[newp.c][newp.x][newp.y]=newp.tm;
                }

                if ((a[newp.c][newp.x][newp.y]=='P')&&(newp.tm<=t))
                {
                    ok=true;
                    break;
                }
                //printf("newp push,c=%d,x=%d,y=%d,time=%d\n",newp.c,newp.x,newp.y,newp.tm);getchar();
                que.push(newp);
            }

        }

        //输出结果
        if (ok==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
