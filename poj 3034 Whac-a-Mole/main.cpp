
#include <iostream>
#include <cstring>

using namespace std;

const int O=1e9;
const int M=15;

const int grid[11][11]={{O, O, O, O, O, 5, O, O, O, O, O},
                    {O, O, 5, 5, 5, 4, 5, 5, 5, O, O},
                    {O, 5, 5, 4, 4, 3, 4, 4, 5, 5, O},
                    {O, 5, 4, 3, 3, 2, 3, 3, 4, 5, O},
                    {O, 5, 4, 3, 2, 1, 2, 3, 4, 5, O},
                    {5, 4, 3, 2, 1, O, 1, 2, 3, 4, 5},
                    {O, 5, 4, 3, 2, 1, 2, 3, 4, 5, O},
                    {O, 5, 4, 3, 3, 2, 3, 3, 4, 5, O},
                    {O, 5, 5, 4, 4, 3, 4, 4, 5, 5, O},
                    {O, O, 5, 5, 5, 4, 5, 5, 5, O, O},
                    {O, O, O, O, O, 5, O, O, O, O, O}};

int n,m,d;
int f[21][50][50];
bool v[21][50][50];
int mt;

int abs(int x){return x<0?-x:x;}

inline int gcd(int a,int b){return a?gcd(b%a,a):b;}

int score(int k, int x1, int y1, int x2, int y2)
{

    int ret=0;
    int dx=x2-x1;
    int dy=y2-y1;
    int x,y;

    if (dx*dx+dy*dy>d*d) return 0;
    if ( dx==0&&dy==0 ) return v[k][x1][x2];

    if ( dx==0 )
    {
        if ( y1>y2 ) swap(y1,y2);
        for (int i=y1;i<=y2;i++)
        {
            ret+=v[k][x1][i];
        }
        return ret;
    }

    if ( dy==0 )
    {
        if ( x1>x2 ) swap(x1,x2);
        for (int i=x1;i<=x2;i++)
        {
            ret+=v[k][i][y1];
        }
        return ret;
    }

    int d=gcd(abs(dx),abs(dy));
    dx/=d;
    dy/=d;

    for ( int i=0;i<=d;i++ )
    {
        ret+=v[k][x1+dx*i][y1+dy*i];
    }
    return ret;
}

int main()
{
    while (cin>>n>>d>>m)
    {
        if (n==0&&m==0&&d==0) break;
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        mt=0;
        for (int i=0;i<m;i++)
        {
            int x,y,t;
            cin>>x>>y>>t;
            v[t][d+x][d+y]=true;
            if (t>mt) mt=t;
        }
        n=d+n+d;
        for (int k=1;k<=mt;k++)
        {
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                {
                    int sx=i-d<0 ? 0 : i-d;
                    int tx=i+d>=n ? n-1 : i+d;
                    int sy=j-d<0 ? 0 : j-d;
                    int ty=j+d>=n ? n-1 : j+d;
                    f[k][i][j]=f[k-1][i][j]+v[k][i][j];
                    for (int dx=sx;dx<=tx;dx++)
                    {
                        for (int dy=sy;dy<=ty;dy++)
                        {
                            if ( (dx-i)*(dx-i)+(dy-j)*(dy-j)<=d*d )
                            {
                                int scr=score( k, i, j, dx, dy );
                                f[k][i][j]=max(f[k][i][j], f[k-1][dx][dy]+scr);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                ans=max( ans, f[mt][i][j] );
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}



/*
#include <iostream>
#include <cstring>

using namespace std;

const int O=1e9;
const int M=5;

const int grid[11][11]={{O, O, O, O, O, 5, O, O, O, O, O},
                    {O, O, 5, 5, 5, 4, 5, 5, 5, O, O},
                    {O, 5, 5, 4, 4, 3, 4, 4, 5, 5, O},
                    {O, 5, 4, 3, 3, 2, 3, 3, 4, 5, O},
                    {O, 5, 4, 3, 2, 1, 2, 3, 4, 5, O},
                    {5, 4, 3, 2, 1, O, 1, 2, 3, 4, 5},
                    {O, 5, 4, 3, 2, 1, 2, 3, 4, 5, O},
                    {O, 5, 4, 3, 3, 2, 3, 3, 4, 5, O},
                    {O, 5, 5, 4, 4, 3, 4, 4, 5, 5, O},
                    {O, O, 5, 5, 5, 4, 5, 5, 5, O, O},
                    {O, O, O, O, O, 5, O, O, O, O, O}};

int n,m,d;
int f[21][45][45];
bool v[21][45][45];
int mt;

int abs(int x){return x<0?-x:x;}

inline int gcd(int a,int b){return a?gcd(b%a,a):b;}

int score(int k, int x1, int y1, int x2, int y2)
{
    int d=gcd(abs(x2-x1),abs(y2-y1));
    int ret=0;
    int dx=(x2-x1)/d;
    int dy=(y2-y1)/d;
    int x,y;
    for ( x=x1,y=y1;x!=x2||y!=y2;x+=dx,y+=dy )
    {
        if (v[k][x1][y1]) ret++;
    }
    if (v[k][x2][y2]) ret++;
    return ret;
}

int main()
{
    while (cin>>n>>d>>m)
    {
        if (n==0&&m==0&&d==0) break;
        memset(f,0,sizeof(f));
        memset(v,0,sizeof(v));
        for (int i=0;i<m;i++)
        {
            int x,y,t;
            cin>>x>>y>>t;
            v[t][M+x][M+y]=true;
        }
        for (int k=1;k<=m;k++)
        {
            for (int i=M-d;i<M+n+d;i++)
            {
                for (int j=M-d;j<M+n+d;j++)
                {
                    f[k][i][j]=f[k-1][i][j]+v[k][i][j];
                    for (int dx=M-d;dx<=M+d;dx++)
                    {
                        for (int dy=M-d;dy<=M+d;dy++)
                        {
                            if ( grid[dx][dy]<=d )
                            {
                                if ( i+(dx-M)<0||j+(dy-M)<0||i+(dx-M)>=M+n+d||j+(dy-M)>=M+n+d ) continue;
                                int scr=score( k, i, j, i+(dx-M), j+(dy-M) );
                                f[k][i][j]=max(f[k][i][j], f[k-1][i+(dx-M)][j+(dy-M)]+scr);
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for (int i=M;i<M+n;i++)
        {
            for (int j=M;j<M+n;j++)
            {
                ans=max( ans, f[m][i][j] );
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
