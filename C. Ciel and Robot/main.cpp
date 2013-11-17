#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int direct[4][2]={ {0,1},{0,-1},{-1,0},{1,0} };//U, D, L, R
const long long MX=1e9;

struct POINT{
    long long x;
    long long y;
    POINT(long long _x=0,long long _y=0)
    {
        x=_x;
        y=_y;
    }
    void output()
    {
        cerr<<"p "<<x<<" "<<y<<endl;
    }
};

char s[111];
POINT a[222];
int ex,ey;
int n;

bool onSegment(POINT Pi,POINT Pj,POINT Q)
{
    if ( (Q.x-Pi.x)*(Pj.y-Pi.y)==(Pj.x-Pi.x)*(Q.y-Pi.y)&&
        min(Pi.x,Pj.x)<=Q.x&&Q.x<=max(Pi.x,Pj.x)&&
        min(Pi.y,Pj.y)<=Q.y&&Q.y<=max(Pi.y,Pj.y))
        return true;
    else
        return false;
}

int main()
{
    cin>>ex>>ey;
    cin>>(s+1);
    int n=strlen(s+1);
    POINT tmp;
    tmp.x=0;
    tmp.y=0;
    a[0]=tmp;
    for (int i=1;i<=n;i++)
    {
        a[i].x=a[i-1].x;
        a[i].y=a[i-1].y;
        if (s[i]=='U')
        {
            a[i].x+=direct[0][0];
            a[i].y+=direct[0][1];
        }
        if (s[i]=='D')
        {
            a[i].x+=direct[1][0];
            a[i].y+=direct[1][1];
        }
        if (s[i]=='L')
        {
            a[i].x+=direct[2][0];
            a[i].y+=direct[2][1];
        }
        if (s[i]=='R')
        {
            a[i].x+=direct[3][0];
            a[i].y+=direct[3][1];
        }
    }
    for (int i=n+1;i<=n+n;i++)
    {
        a[i].x=a[i-1].x;
        a[i].y=a[i-1].y;
        if (s[i-n]=='U')
        {
            a[i].x+=direct[0][0];
            a[i].y+=direct[0][1];
        }
        if (s[i-n]=='D')
        {
            a[i].x+=direct[1][0];
            a[i].y+=direct[1][1];
        }
        if (s[i-n]=='L')
        {
            a[i].x+=direct[2][0];
            a[i].y+=direct[2][1];
        }
        if (s[i-n]=='R')
        {
            a[i].x+=direct[3][0];
            a[i].y+=direct[3][1];
        }
    }

    //for (int i=1;i<=n;i++) cerr<<"ai="<<a[i].x<<" "<<a[i].y<<" ai+n="<<a[i+n].x<<" "<<a[i+n].y<<endl;


    bool flag=false;
    for (int i=0;i<=n;i++)
    {
        long long x,y,bit=MX;
        POINT Pi(a[i].x,a[i].y);
        if (a[i+n].x-a[i].x!=0) bit=min(bit,abs(MX/(a[i+n].x-a[i].x)));
        if (a[i+n].y-a[i].y!=0) bit=min(bit,abs(MX/(a[i+n].y-a[i].y)));
        x=(bit+1)*(a[i+n].x-a[i].x)+a[i].x;
        y=(bit+1)*(a[i+n].y-a[i].y)+a[i].y;
        POINT Pj(x,y);
        POINT Q(ex,ey);
        //Pi.output();
        //Pj.output();
        //Q.output();
        //cerr<<(Q.x-Pi.x)*(Pj.y-Pi.y)<<endl;
        //cerr<<(Pj.x-Pi.x)*(Q.y-Pi.y)<<endl;
        //cerr<<"----"<<endl;
        if ( onSegment(Pi,Pj,Q) )
        {
            if (((a[i+n].x-a[i].x==0)||(ex-a[i].x)%(a[i+n].x-a[i].x)==0)&&
                ((a[i+n].y-a[i].y==0)||(ey-a[i].y)%(a[i+n].y-a[i].y)==0))
            {
                flag=true;
                break;
            }
        }
    }
    if (flag) puts("Yes");
    else puts("No");
    return 0;
}

