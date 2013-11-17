#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
    int z;
    int step;
}POINT;

queue<POINT>que;

int mov[6][3]={ {1,0,0},{0,1,0},{0,0,1},{-1,0,0},{0,-1,0},{0,0,-1} };

int am[11][11][11];

char map[11][11][11];
int n;
POINT bg,ed,p,tmp,ans;
string str;
bool ok;

int main()
{
    while (cin >> str)
    {
        if (str!="START") continue;
        cin >> n;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                for (int k=0;k<n;k++)
                {
                    cin >> map[i][j][k];
                    am[i][j][k]=0;
                }
            }
        }
        cin >> bg.x >> bg.y >> bg.z;
        cin >> ed.x >> ed.y >> ed.z;
        cin >> str;
        if (str!="END") continue;
        while (!que.empty()) que.pop();
        p.x=bg.x;
        p.y=bg.y;
        p.z=bg.z;
        p.step=0;
        am[p.z][p.x][p.y]=1;
        que.push(p);
        ok=false;
        while (!que.empty())
        {
            tmp=que.front();
            que.pop();
            if ( tmp.x==ed.x && tmp.y==ed.y && tmp.z==ed.z )
            {
                ok=true;
                ans=tmp;
                break;
            }
            for (int i=0;i<6;i++)
            {
                p.x=tmp.x+mov[i][0];
                p.y=tmp.y+mov[i][1];
                p.z=tmp.z+mov[i][2];
                p.step=tmp.step+1;
                if ( p.x>=0 && p.x<n && p.y>=0 && p.y<n && p.z>=0 && p.z<n && map[p.z][p.x][p.y]!='X' && am[p.z][p.x][p.y]==0)
                {
                    am[p.z][p.x][p.y]=1;
                    que.push(p);
                }
            }
        }
        if (ok==false)
        {
            cout << "NO ROUTE"<<endl;
        }
        else
        {
            cout << n << " " << ans.step << endl;
        }
    }
    return 0;
}
