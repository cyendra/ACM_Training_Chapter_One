/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef struct{
    int x;
    int y;
}POINT;

POINT a[4];
POINT b[4];

int direct[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };
int direct2[4][2]={ {0,2},{2,0},{-2,0},{0,-2} };

int map[10][10];

bool ok;
void dfs(int deep);
bool check(int x,int y);

bool check(int x,int y)
{
    if ( x>=0&&x<8&&y>=0&&y<8 ) return true;
    else return false;
}

void dfs(int deep)
{
    int lx,ly;
    if (ok) return;
    if ( deep>8 ) return;
    for (int i=0;i<4;i++)
    {
        if ( map[ b[i].x ][ b[i].y ]==1 )
        {
            ok=true;
            return;
        }
    }
    for (int i=0;i<4;i++)
    {
        lx=a[i].x;
        ly=a[i].y;
        for (int j=0;j<4;j++)
        {
            if ( check( lx+direct[j][0] , ly+direct[j][1] )
                && map[ lx+direct[j][0] ][ ly+direct[j][1] ]==0 )
            {
                map[lx][ly]=0;
                map[ lx+direct[j][0] ][ ly+direct[j][1] ]=1;
                a[i].x=lx+direct[j][0];
                a[i].y=ly+direct[j][1];
                dfs(deep+1);
                a[i].x=lx;
                a[i].y=ly;
                map[lx][ly]=1;
                map[ lx+direct[j][0] ][ ly+direct[j][1] ]=0;
            }
            else if ( check( lx+direct2[j][0] , ly+direct2[j][1] )
                      && map[ lx+direct2[j][0] ][ ly+direct2[j][1] ]==0
                      && check( lx+direct[j][0] , ly+direct[j][1])
                      && map[ lx+direct[j][0] ][ ly+direct[j][1] ]==1 )
            {
                map[lx][ly]=0;
                map[ lx+direct2[j][0] ][ ly+direct2[j][1] ]=1;
                a[i].x=lx+direct2[j][0];
                a[i].y=ly+direct2[j][1];
                dfs(deep+1);
                a[i].x=lx;
                a[i].y=ly;
                map[lx][ly]=1;
                map[ lx+direct2[j][0] ][ ly+direct2[j][1] ]=0;
            }
        }
    }
}

int main()
{
    while ( cin >> a[0].x >> a[0].y )
    {
        for (int i=1;i<=3;i++)
        {
            cin >> a[i].x >> a[i].y;
        }
        for (int i=0;i<4;i++)
        {
            cin >> b[i].x >> b[i].y;
        }
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                map[i][j]=0;
            }
        }
        for (int i=0;i<4;i++)
        {
            map[ a[i].x ][ a[i].y ]=1;
        }
        ok=false;
        dfs(1);
        if (ok==true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
*/

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
class Node
{
public:
   int x,y;
};
class T
{
public:
   Node node[4];
   int step;
};
queue<T>q1;
queue<T>q2;
const int d[4][2] = { 0,1,1,0,-1,0,0,-1 };
char hash[8][8][8][8][8][8][8][8];
//构造一个4给点组成的图，1代表由A开始走过的点；2代表由B开始走过的点
bool cmp( Node a, Node b )
{
   if( a.x == b.x )
       return a.y < b.y;
   return a.x < b.x;
}
char getnum( T t  )//得到标记的值
{
     return hash[t.node[0].x][t.node[0].y][t.node[1].x][t.node[1].y]
            [t.node[2].x][t.node[2].y][t.node[3].x][t.node[3].y];
}
void setnum( T t , char value ) //给标记赋值
{
    hash[t.node[0].x][t.node[0].y][t.node[1].x][t.node[1].y]
    [t.node[2].x][t.node[2].y][t.node[3].x][t.node[3].y] = value;
}
bool judge( T &t , int i , int j , int m )//判断是否可以走
{
   if( m==1 )
   {
       if( t.step >=4 )//最多移动4步
           return false;
       t.step ++;
   }
   t.node[i].x += d[j][0];
   t.node[i].y += d[j][1];
   if( t.node[i].x >= 0 && t.node[i].x < 8 && t.node[i].y >=0 && t.node[i].y<8 )
   {   int k;
        for(  k = 0 ; k< 4 ; k++ )
       {
           if( i!=k )
           {
               if( t.node[i].x==t.node[k].x&&t.node[i].y==t.node[k].y )//判断是否有点
               if( m == 1 ) return judge( t , i , j , 2 );//判断是否跳过相邻的点可以合法走动
               else return false;
           }
       }
       if( k>=4 )
       {
         sort( t.node , t.node + 4 , cmp );
         return true;
       }
    }
   return false;
}
bool BFS(  )
{
   T s;
   while( !q1.empty()||!q2.empty() )//双向搜索
   {
       if( !q1.empty( ) )
       {
            for( int i = 0 ; i< 4 ;i++ )
              for( int j = 0 ; j< 4 ; j++ )
              {    s = q1.front();
                   if( judge( s , i , j ,1 ) )//判断是否可以移动
                   {
                        char c = getnum( s );
                        if( c  == 2 )//如果B已经到了这个点就表示可以从A移动到B
                          return true;
                        else  if( c == 0 )//如果该点没有标记
                         {
                              setnum( s , 1 );
                              q1.push( s );
                         }
                   }
              }
              q1.pop();
       }
       if( !q2.empty( ) )
       {
            for( int i = 0 ; i< 4 ;i++ )
              for( int j = 0 ; j< 4 ; j++ )
              {  s = q2.front();
                   if( judge( s , i , j ,1 ) )
                   {
                        char c = getnum( s );
                        if( c  == 1 )
                          return true;
                        else  if( c == 0 )
                         {
                              setnum( s , 2 );
                              q2.push( s );
                         }
                   }
              }
              q2.pop();
       }
   }
   return false;
}
int main( )
{
    T A,B;
    int x ,y;
    while( scanf( "%d%d",&x,&y )==2 )
    {
        memset( hash, 0 , sizeof( hash ) );
        while( !q1.empty() )
              q1.pop();
        while( !q2.empty() )
               q2.pop();
        A.node[0].x = --x;
        A.node[0].y = --y;
        for( int i = 1; i< 4 ;i++ )
        {
           scanf( "%d%d",&x , &y );
           A.node[i].x = --x;
           A.node[i].y = --y;
        }
        A.step = 0; setnum( A , 1 );
        for( int i = 0 ; i< 4 ;i++ )
        {
           scanf( "%d%d",&x , &y );
           B.node[i].x = --x;
           B.node[i].y = --y;
        }
        B.step  = 0; setnum( B, 2 );
        sort( A.node ,A.node + 4 , cmp );
        sort( B.node , B.node + 4 ,cmp );
        q1.push( A );
        q2.push( B );
        if( BFS() ) printf( "YES\n" );
        else printf( "NO\n" );
    }
    return 0;
}
