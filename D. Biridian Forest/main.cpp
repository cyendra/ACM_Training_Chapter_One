#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
const int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
const int INF=1e9+7;
struct POINT{
    int x;
    int y;
    int dp;
    POINT(int a=0,int b=0,int c=0):x(a),y(b),dp(c){}
};
char s[1111][1111];
int r,c,len;
int ret;
POINT door,start;

bool check(POINT p)
{
    if (p.x>=0&&p.x<r&&p.y>=0&&p.y<c) return true;
    return false;
}
vector<int>ans;
vector<int>num;

void bfs(POINT pin)
{
    POINT p,tmp;
    bool vis[1111][1111];
    queue<POINT>que;
    memset(vis,0,sizeof(vis));
    while (!que.empty()) que.pop();
    pin.dp=0;
    que.push(pin);
    vis[pin.x][pin.y]=true;
    while (!que.empty())
    {
        tmp=que.front();
        que.pop();
        for (int i=0;i<4;i++)
        {
            p.x=tmp.x+direct[i][0];
            p.y=tmp.y+direct[i][1];
            p.dp=tmp.dp+1;
            if (check(p)&&!vis[p.x][p.y]&&s[p.x][p.y]!='T')
            {
                vis[p.x][p.y]=true;
                que.push(p);
                if ( s[p.x][p.y]>='1'&&s[p.x][p.y]<='9' )
                {
                    ans.push_back(p.dp);
                    num.push_back(s[p.x][p.y]-'0');
                }
                if ( s[p.x][p.y]=='S' ) len=p.dp;
            }
        }
    }
}

int main()
{
    ans.clear();
    num.clear();
    ret=0;
    len=INF;
    cin>>r>>c;
    for (int i=0;i<r;i++) cin>>s[i];
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (s[i][j]=='S')
            {
                start.x=i;
                start.y=j;
                start.dp=0;
            }
            if (s[i][j]=='E')
            {
                door.x=i;
                door.y=j;
                door.dp=0;
            }
        }
    }
    bfs(door);
    for (int i=0;i<ans.size();i++)
    {
        if (ans[i]<=len) ret+=num[i];
    }
    cout<<ret<<endl;
    return 0;
}
