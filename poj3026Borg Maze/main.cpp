#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#define OO 9999999

using namespace std;

typedef struct{
    int x;
    int y;
    int step;
}POINT;

int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };

POINT pot[500];//储存S与A
char chr[500][500];//储存asc码地图
int map[500][500];//储存数字地图，0代表通路,OO代表墙,1~100代表S与A
bool bm[500][500];
int a[500][500];//邻接矩阵存图
int d[500];//最小生成树
bool v[500];//集合标记

queue <POINT> que;//bfs用队列
POINT tmp,p;//bfs用变量

int main()
{
    int T;//样例数
    int A,B;//储存坐标边界
    int n;//表示A点个数
    int find;//表示bfs时找到几个点
    int t,mind;//prim用变量
    int ans;
    cin>>T;
    while (T--)
    {
        n=1;
        cin>>B>>A;
        for (int i=0;i<=A;i++)
        {
            cin.getline(chr[i],100,'\n');
        }
        for (int i=1;i<=A;i++)
        {
            for (int j=1;j<=B;j++)
            {
                if (chr[i][j-1]==' ')
                {
                    map[i][j]=0;
                }
                else if (chr[i][j-1]=='#')
                {
                    map[i][j]=OO;
                }
                else if (chr[i][j-1]=='S')
                {
                    map[i][j]=1;
                    pot[1].x=i;
                    pot[1].y=j;
                }
                else if (chr[i][j-1]=='A')
                {
                    n++;
                    map[i][j]=n;
                    pot[n].x=i;
                    pot[n].y=j;
                }
            }
        }
        //读入地图
        /*
        for (int i=1;i<=A;i++)
        {
            for (int j=1;j<=B;j++)
            {
                cout<<map[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        //验证完毕
        memset(a,0,sizeof(a));
        for (int pl=1;pl<=n;pl++)
        {
            memset(bm,0,sizeof(bm));
            while (!que.empty()) que.pop();
            p=pot[pl];
            p.step=0;
            que.push(p);
            bm[p.x][p.y]=true;
            find=n;
            while (!que.empty()&&find>0)
            {
                tmp=que.front();
                que.pop();
                if ( map[tmp.x][tmp.y]!=0 )
                {
                    a[ pl ][ map[tmp.x][tmp.y] ]=tmp.step;
                    a[ map[tmp.x][tmp.y] ][ pl ]=tmp.step;
                    find--;
                }
                for (int i=0;i<4;i++)
                {
                    p=tmp;
                    p.x=p.x+direct[i][0];
                    p.y=p.y+direct[i][1];
                    p.step=p.step+1;
                    if ( p.x>=1&&p.x<=A&&p.y>=1&&p.y<=B&&map[p.x][p.y]!=OO&&bm[p.x][p.y]!=true )
                    {
                        bm[p.x][p.y]=true;
                        que.push(p);
                    }
                }
            }
        }
        //bfs求矩阵
        /*
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        //检验完毕
        ans=0;
        memset(v,0,sizeof(v));
        for (int i=0;i<=n;i++) d[i]=OO;
        d[1]=0;
        for (int loop=1;loop<=n;loop++)
        {
            mind=OO;
            for (int i=1;i<=n;i++)
            {
                if (!v[i]&&d[i]<mind)
                {
                    mind=d[i];
                    t=i;
                }
            }
            v[t]=true;
            ans+=mind;
            for (int i=1;i<=n;i++)
            {
                if (a[t][i]<d[i])
                {
                    d[i]=a[t][i];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
