#include <iostream>
#include <cstring>
using namespace std;

int direct[4][2]={ {-1,0},{1,0},{0,-1},{0,1} };
//int revd[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
int ud[4]={ 0,1,2,3 };//U D L R

int map[300][300];
int len;
int x,y;
char mv[150];
int to;
bool ok;

int main()
{
    memset(map,0,sizeof(map));
    cin >> mv;
    len=strlen(mv);
    x=150;
    y=150;
    ok=true;
    for (int i=0;i<len&&ok==true;i++)
    {
        map[x][y]=1;
        if ( mv[i]=='U' )
        {
            to=0;
        }
        else if ( mv[i]=='D' )
        {
            to=1;
        }
        else if ( mv[i]=='L')
        {
            to=2;
        }
        else if ( mv[i]=='R' )
        {
            to=3;
        }
        x+=direct[to][0];
        y+=direct[to][1];
        if ( map[x][y]==1 )
        {
            ok=false;
            break;
        }
        for (int k=0;k<4;k++)
        {
            if (k!=to)
            {
                if ( map[ x-direct[k][0] ][ y-direct[k][1] ]==1 )
                {
                    ok=false;
                    break;
                }
            }
        }
    }
    if (ok==true)
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "BUG" << endl;
    }
    return 0;
}
