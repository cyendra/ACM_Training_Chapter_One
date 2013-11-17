#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int Y,W,fz,fm;
    cin >> Y >> W;
    if ( Y>W ) fz=Y;
    else fz=W;
    fm=6;
    fz=7-fz;
    if (fz==0)
    {
        cout << "0/1" << endl;
    }
    else if (fz==fm)
    {
        cout << "1/1" << endl;
    }
    else
    {
        while ( fz%2==0 && fm%2==0 )
        {
            fz=fz/2;
            fm=fm/2;
        }
        while ( fz%3==0 && fm%3==0 )
        {
            fz=fz/3;
            fm=fm/3;
        }
        cout << fz << "/" << fm << endl;
    }
    return 0;
}
