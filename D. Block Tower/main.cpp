#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn=555;
const int direct[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };

struct ANS_NODE{
    int x;
    int y;
    char c;
    ANS_NODE(int _x,int _y,char _c):x(_x),y(_y),c(_c){}
};

char map[maxn][maxn];
bool visit[maxn][maxn];
vector<ANS_NODE>ans;
vector<ANS_NODE>::iterator it;
int n,m;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

void dfs(int x,int y,int d)
{
    visit[x][y]=true;
    ans.push_back(ANS_NODE(x,y,'B'));
    for (int i=0;i<4;i++)
    {
        int dx=x+direct[i][0];
        int dy=y+direct[i][1];
        if (check(dx,dy)&&map[dx][dy]!='#'&&!visit[dx][dy])
        {
            dfs(dx,dy,d+1);
        }
    }
    if (d)
    {
        ans.push_back(ANS_NODE(x,y,'D'));
        ans.push_back(ANS_NODE(x,y,'R'));
    }
}

int main()
{
    while (cin>>n>>m)
    {
        ans.clear();
        memset(visit,0,sizeof(visit));
        for (int i=1;i<=n;i++) cin>>(map[i]+1);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (!visit[i][j]&&map[i][j]!='#') dfs(i,j,0);
            }
        }
        cout<<ans.size()<<endl;
        for (it=ans.begin();it!=ans.end();it++)
        {
            cout<<it->c<<" "<<it->x<<" "<<it->y<<endl;
        }
    }
    return 0;
}
