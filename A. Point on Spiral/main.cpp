#include <iostream>

using namespace std;

const int direct[4][2]= { {1,0},{0,1},{-1,0},{0,-1} };

int d,l;
int x,y;
int ans;
int px,py;
int ntm;
bool flag;
int ltm;
int dir;

int main()
{
    ans=0;
    cin>>x>>y;
    px=0;
    py=0;
    ntm=1;
    ltm=1;
    flag=false;
    dir=0;
    while ( px!=x||py!=y )
    {
        if ( ltm==0&&flag==false )
        {
            dir=(dir+1)%4;
            ans++;
            ltm=ntm;
            flag=true;
        }
        else if ( ltm==0&&flag==true )
        {
            dir=(dir+1)%4;
            ans++;
            ntm++;
            ltm=ntm;
            flag=false;
        }
        px+=direct[dir][0];
        py+=direct[dir][1];
        ltm--;
    }
    cout<<ans<<endl;
    return 0;
}
