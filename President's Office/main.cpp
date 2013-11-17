#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int direct[4][2]={ {0,1},{1,0},{-1,0},{0,-1} };
char dc[200][200];
map<char,int>mp;
map<char,int>mapa;
//map<char,int>::iterator it;
int ans;

int main()
{
    int n ,m,x,y;
    char boss;
    mp.clear();
    mapa.clear();
    cin >> n >> m >> boss;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> dc[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if ( dc[i][j]==boss )
            for (int mv=0;mv<4;mv++)
            {
                x=i+direct[mv][0];
                y=j+direct[mv][1];
                if ( x>=0&&x<n&&y>=0&&y<m&&dc[x][y]!=boss && dc[x][y]!='.' )
                {
                    mp[ dc[x][y] ]++;
                }
            }
        }
    }
    ans=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if ( dc[i][j]!=boss && dc[i][j]!='.' && mp[dc[i][j]]>0 && mapa[dc[i][j]]!=1 )
            {
                ans++;
                mapa[ dc[i][j] ]=1;
                //cout << dc[i][j] <<endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
