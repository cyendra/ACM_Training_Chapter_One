#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
char map[333][333];
int n,m;

void set(char c)
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            map[i][j]=c;
        }
    }
}

void print(int x1,int y1,int x2,int y2,char c)
{
    for (int i=y1;i<=y2&&i<=n;i++)
    {
        for (int j=x1;j<=x2&&j<=m;j++)
        {
            map[i][j]=c;
        }
    }
}

struct POINT{
    int x;
    int y;
};


int main()
{
    char c,chr;
    int x,y;
    int x1,x2,y1,y2;
    char name[333];
    while (cin>>c)
    {
        if (c=='X') break;
        else if (c=='I')
        {
            cin>>m>>n;
            set('O');
        }
        else if (c=='C')
        {
            set('O');
        }
        else if (c=='L')
        {
            cin>>x>>y>>chr;
            map[y][x]=chr;
        }
        else if (c=='V')
        {
            cin>>x>>y1>>y2>>chr;
            if (y1>y2) swap(y1,y2);
            print(x,y1,x,y2,chr);
        }
        else if (c=='H')
        {
            cin>>x1>>x2>>y>>chr;
            if (x1>x2) swap(x1,x2);
            print(x1,y,x2,y,chr);
        }
        else if (c=='K')
        {
            cin>>x1>>y1>>x2>>y2>>chr;
            if (x1>x2) swap(x1,x2);
            if (y1>y2) swap(y1,y2);
            print(x1,y1,x2,y2,chr);
        }
        else if (c=='F')
        {
            cin>>x>>y>>chr;
            queue<POINT>que;
            while (!que.empty()) que.pop();
            POINT p;
            p.x=y;
            p.y=x;
            char tel=map[p.x][p.y];
            if (tel==chr) continue;
            que.push(p);
            map[p.x][p.y]=chr;
            while (!que.empty())
            {
                POINT tmp=que.front();
                que.pop();
                for (int i=0;i<4;i++)
                {
                    p.x=tmp.x+direct[i][0];
                    p.y=tmp.y+direct[i][1];
                    if (p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m&&map[p.x][p.y]==tel)
                    {
                        map[p.x][p.y]=chr;
                        que.push(p);
                    }
                }
            }
        }
        else if (c=='S')
        {
            cin>>name;
            cout<<name<<endl;
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=m;j++)
                {
                    cout<<map[i][j];
                }
                cout<<endl;
            }
        }
        else
        {
            continue;
        }
    }
    return 0;
}
