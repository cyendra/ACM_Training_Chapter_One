#include <iostream>
#include <cstdio>
using namespace std;

char a[4][4];

int main()
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }
    bool ok=true;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (a[i][j]!=a[2-i][2-j])
            {
                ok=false;
            }
        }
    }
    if (ok==true)
    {
        cout << "YES"<<endl;
    }
    else
    {
        cout << "NO"<<endl;
    }
    return 0;
}
