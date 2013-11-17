#include <iostream>
#include <cmath>
using namespace std;

int dit[6][2]={ {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1} };

bool check(int x1,int y1,int x2,int y2,int x3,int y3)
{
    double a,b,c,csa,csb,csc;
    if ( (y2-y1)*(x3-x1)==(y3-y1)*(x2-x1) )
    {
        return false;
    }
    a=sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
    b=sqrt(1.0*(x1-x3)*(x1-x3) + 1.0*(y1-y3)*(y1-y3));
    c=sqrt(1.0*(x2-x3)*(x2-x3) + 1.0*(y2-y3)*(y2-y3));
    csa=( (x2-x1)*(x3-x1)+(y2-y1)*(y3-y1) )/(b*c);
    csc=( (x2-x3)*(x1-x3)+(y2-y3)*(y1-y3) )/(a*b);
    csb=( (x1-x2)*(x3-x2)+(y1-y2)*(y3-y2) )/(a*c);
    if (csa==0||csc==0||csb==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int X[4],Y[4];
    bool b1,b2,b3,ok;
    for (int i=1;i<=3;i++)
    {
        cin>>X[i]>>Y[i];
    }
    if ( check(X[1],Y[1],X[2],Y[2],X[3],Y[3]) )
    {
        cout<<"RIGHT"<<endl;
    }
    else
    {
        ok=false;
        for (int i=0;i<4;i++)
        {
            b1=check(X[1]+dit[i][0],Y[1]+dit[i][1],X[2],Y[2],X[3],Y[3]);
            b2=check(X[1],Y[1],X[2]+dit[i][0],Y[2]+dit[i][1],X[3],Y[3]);
            b3=check(X[1],Y[1],X[2],Y[2],X[3]+dit[i][0],Y[3]+dit[i][1]);
           //cout<<b1<<b2<<b3<<endl;
            if (b1||b2||b3)
            {
                ok=true;
            }
        }
        if (ok==true)
        {
            cout<<"ALMOST"<<endl;
        }
        else
        {
            cout<<"NEITHER"<<endl;
        }
    }
    return 0;
}
