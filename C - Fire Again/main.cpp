//#include <iostream>
#include <cstring>
#include <queue>
#include<fstream>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

struct POINT{
    int x;
    int y;
};

queue<POINT>que;
POINT p,tmp;

int direct[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };

int n,m;
int K;
bool flag;

int a[2222][2222];

int num;
POINT ans;

int main()
{
    memset(a,0,sizeof(a));
    cin>>n>>m;
    cin>>K;
    num=n*m;
    flag=false;
    while (!que.empty()) que.pop();
    for (int i=1;i<=K;i++)
    {
        cin>>p.x>>p.y;
        a[ p.x ][ p.y ]=1;
        que.push(p);
        ans=p;
        num--;
    }
    if ( num==0 ) flag=true;
    while ( !que.empty() )
    {
        if (flag) break;
        tmp=que.front();
        que.pop();
        for (int i=0;i<4;i++)
        {
            if (flag) break;
            p.x=tmp.x+direct[i][0];
            p.y=tmp.y+direct[i][1];
            if ( p.x>=1&&p.x<=n&&p.y>=1&&p.y<=m&&a[p.x][p.y]==0 )
            {
                a[p.x][p.y]=1;
                que.push(p);
                num--;
                if (num==0)
                {
                    ans=p;
                    flag=true;
                    break;
                }
            }
        }
    }
    cout<<ans.x<<" "<<ans.y<<endl;
    return 0;
}

