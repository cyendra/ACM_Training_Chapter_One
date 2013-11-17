#include <iostream>

using namespace std;

char c1,c2;
int x1,x2,y1,y2,dx,dy;
int n;
string ans[100];

int main()
{
    cin>>c1>>y1;
    cin>>c2>>y2;
    x1=c1-'a'+1;
    x2=c2-'a'+1;
    n=0;
    while ( x1!=x2||y1!=y2 )
    {

        dx=dy=0;
        ans[n]="";
        if ( x2>x1 )
        {
            ans[n]+="R";
            dx=1;
        }
        else if (x2<x1)
        {
            ans[n]+="L";
            dx=-1;
        }
        if ( y2>y1 )
        {
            ans[n]+="U";
            dy=1;
        }
        else if (y2<y1)
        {
            ans[n]+="D";
            dy=-1;
        }
        x1+=dx;
        y1+=dy;
        n++;
    }
    cout<<n<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
