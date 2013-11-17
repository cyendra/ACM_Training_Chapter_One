#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int direct[6][3]={ {0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0} };

char map[20][20][20];
int l,n,m;
bool v[20][20][20];

typedef struct {
    int x;
    int y;
    int z;
}dt;

queue<dt>que;

dt p,tmp;

int bgx,bgy;

bool check(dt a)
{
    if (a.z>=1&&a.z<=l&&a.x>=1&&a.x<=n&&a.y>=1&&a.y<=m) return true;
    else return false;
}

int main()
{
    int ans=0;
    memset(map,0,sizeof(map));
    memset(v,0,sizeof(v));
    while (!que.empty()) que.pop();
    cin>>l>>n>>m;
    for (int k=1;k<=l;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>map[k][i][j];
            }
        }
    }
    cin>>bgx>>bgy;
    p.x=bgx;
    p.y=bgy;
    p.z=1;
    v[1][bgx][bgy]=true;
    if (map[p.z][p.x][p.y]=='.') que.push(p);
    while (!que.empty())
    {
        ans++;
        tmp=que.front();
        que.pop();
        for (int i=0;i<6;i++)
        {
            p=tmp;
            p.z+=direct[i][0];
            p.x+=direct[i][1];
            p.y+=direct[i][2];
            if ( check(p)&&!v[p.z][p.x][p.y]&&map[p.z][p.x][p.y]=='.' )
            {
                v[p.z][p.x][p.y]=true;
                que.push(p);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
