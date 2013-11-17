#include <iostream>
#include <queue>
#define BYTE char
using namespace std;

typedef struct{
    int x;
    int y;
    int  tm;
}POINT;

queue<POINT>que;

int n,m,T;

char map[8][8];
int v[8][8];
bool ok;
int mov[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };

void dfs(POINT p)
{
    POINT tmp;
    if (ok==true) return;
    if ( map[p.x][p.y]=='D' )
    {
        if (p.tm==T)
        {
            ok=true;
            return;
        }
        else
        {
            return;
        }
    }
    for (int i=0;i<4;i++)
    {
        tmp.x=p.x+mov[i][0];
        tmp.y=p.y+mov[i][1];
        tmp.tm=p.tm+1;
        if ( ok==false&&tmp.x>=0 && tmp.x<n && tmp.y>=0 && tmp.y<m && tmp.tm<=T && v[tmp.x][tmp.y]==0 && map[tmp.x][tmp.y]!='X' )
        {
            v[tmp.x][tmp.y]=1;
            //cout << tmp.x << tmp.y << tmp.tm << endl;
            dfs(tmp);
            v[tmp.x][tmp.y]=0;
        }
    }
}

int main()
{
    POINT tp;
    int bgx,bgy,edx,edy;
    while (cin >> n >> m >> T)
    {
        if (n==0 && m==0 && T==0)
        {
            break;
        }
        //cout << n << m << T;
        edx=-1;
        edy=-1;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                cin >> map[i][j];
                v[i][j]=0;
                if (map[i][j]=='S')
                {
                    bgx=i;
                    bgy=j;
                    v[i][j]=1;
                }
                if (map[i][j]=='D')
                {
                    edx=i;
                    edy=j;
                }
            }
        }
        if (edx==-1||edy==-1)
        {
            cout << "NO" << endl;
            continue;
        }

        if ( (bgx+bgy)%2 == (edx+edy)%2 && T%2==1 )
        {
            cout << "NO" << endl;
            continue;
        }
        if ( (bgx+bgy)%2 != (edx+edy)%2 && T%2==0 )
        {
            cout << "NO" << endl;
            continue;
        }
        ok=false;
        tp.x=bgx;
        tp.y=bgy;
        tp.tm=0;
        dfs(tp);
        if (ok==true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
