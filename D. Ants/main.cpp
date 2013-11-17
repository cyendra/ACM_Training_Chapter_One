#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn=1111;
const int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
struct POINT{
    int x;
    int y;
    POINT(int a,int b):x(a),y(b){}
};
int map[maxn][maxn];
int vis[maxn][maxn];
queue<POINT>que;
int num,T;
int main()
{
    memset(map,0,sizeof(map));
    memset(vis,0,sizeof(vis));
    while (!que.empty()) que.pop();
    cin>>num>>T;
    map[500][500]=num;
    que.push(POINT(500,500));
    vis[500][500]=true;
    while (!que.empty())
    {
        POINT p=que.front();
        int v=map[p.x][p.y]/4;
        que.pop();
        vis[p.x][p.y]=false;
        for (int i=0;i<4;i++)
        {
            int x=p.x+direct[i][0];
            int y=p.y+direct[i][1];
            map[x][y]+=v;
            if (!vis[x][y]&&map[x][y]>3)
            {
                que.push(POINT(x,y));
                vis[x][y]=true;
            }
        }
        map[p.x][p.y]%=4;
    }
    while (T--)
    {
        int x,y;
        cin>>x>>y;
        x=abs(x);
        y=abs(y);
        if (x>500||y>500) cout<<0<<endl;
        else cout<<map[500+x][500+y]<<endl;
    }
    return 0;
}
