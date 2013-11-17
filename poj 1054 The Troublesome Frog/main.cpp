#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int r,c,n;

short map[5001][5001];
short f[5001][5001];

struct node{
    short x;
    short y;
};

node a[5001];

bool cmp( node a, node b )
{
    if ( a.x==b.x ) return a.y<b.y;
    else return a.x<b.x;
}

bool check( int x , int y )
{
    if ( x>=1 && x<=r && y>=1 && y<=c ) return true;
    else  return false;
}

int get( int x,int y )
{
    if ( map[x][y]!=0 )
    {
        return map[x][y];
    }
    else return -1;
}

int main()
{
    while (cin>>r>>c)
    {
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            map[ a[i].x ][ a[i].y ]=i;
        }
        short ret=-1;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<i;j++)
            {
                int px=a[j].x-(a[i].x-a[j].x);
                int py=a[j].y-(a[i].y-a[j].y);
                if (check(px,py))
                {
                    int p=get(px,py);
                    if (p!=-1&&f[j][p]!=-1)
                    {
                        f[i][j]=f[j][p]+1;
                    }
                    else
                    {
                        f[i][j]=-1;
                    }
                }
                else
                {
                    f[i][j]=2;
                }
                int nx=a[i].x+(a[i].x-a[j].x);
                int ny=a[i].y+(a[i].y-a[j].y);
                if (!check(nx,ny))
                {
                    ret=max(ret,f[i][j]);
                }
            }
        }
        if (ret<3) cout<<0<<endl;
        else cout<<ret<<endl;
    }
    return 0;
}
