#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int direct[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };

typedef struct{
    int x;
    int y;
    int v;
    int d;
}POINT;

queue<POINT>que;

int n,m;
int T;
char a[555][555];
string s;
int q[555][555];
int f[555][555];
bool v[555][555];
int ans;
int len;

bool check(int x,int y)
{
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    else return false;
}


POINT p,tmp;

void dfs(int x,int y,int k)
{
    int x1,y1;
    //v[x][y]=true;
    if ( k>=len )
    {
        if ( f[x][y]>ans ) ans=f[x][y];
        return;
    }
    for (int i=0;i<4;i++)
    {
        x1=x+direct[i][0];
        y1=y+direct[i][1];
        if ( check(x1,y1)&&a[x1][y1]==s[k+1]&&f[x1][y1]<f[x][y]+q[x1][y1] )
        {
            f[x1][y1]=f[x][y]+q[x1][y1];
            dfs(x1,y1,k+1);
        }
    }
}


int main()
{
    cin>>T;
    while (T--)
    {
        ans=-1;
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        cin>>n>>m;

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>a[i][j];
            }
        }

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                cin>>q[i][j];
            }
        }

        cin>>s;
        s=' '+s;
        len=s.length()-1;

//----------------------

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if ( a[i][j]==s[1]&&q[i][j]>f[i][j] )
                {
                    f[i][j]=q[i][j];
                    //memset(v,0,sizeof(v));
                    dfs(i,j,1);
                }
            }
        }

//----------------------


        cout<<ans<<endl;
    }
    return 0;
}


/*



*/






/*

        while (!que.empty()) que.pop();

        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]==s[1])
                {
                    p.x=i;
                    p.y=j;
                    p.d=1;
                    p.v=q[i][j];
                    que.push(p);
                }
            }
        }

        while (!que.empty())
        {
            p=que.front();
            que.pop();
            for (int i=1)
        }
*/
