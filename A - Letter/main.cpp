#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    char a[100][100];
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int p1,p2,e1,e2;
    bool ok=true;
    p1=0;
    p2=0;
    e1=n;
    e2=m;
    for (int i=0;i<n;i++)
    {
        ok=true;
        for (int j=0;j<m;j++)
        {
            if (a[i][j]!='.')
            {
                ok=false;
            }
        }
        if (ok==true)
        {
            p1++;
        }
        else
        {
            break;
        }
    }

    for (int i=n-1;i>=0;i--)
    {
        ok=true;
        for (int j=0;j<m;j++)
        {
            if (a[i][j]!='.')
            {
                ok=false;
            }
        }
        if (ok==true)
        {
            e1--;
        }
        else
        {
            break;
        }
    }

    for (int j=0;j<m;j++)
    {
        ok=true;
        for (int i=0;i<n;i++)
        {
            if (a[i][j]!='.')
            {
                ok=false;
            }
        }
        if (ok==true)
        {
            p2++;
        }
        else
        {
            break;
        }
    }

    for (int j=m-1;j>=0;j--)
    {
        ok=true;
        for (int i=0;i<n;i++)
        {
            if (a[i][j]!='.')
            {
                ok=false;
            }
        }
        if (ok==true)
        {
            e2--;
        }
        else
        {
            break;
        }
    }

    for (int i=p1;i<e1;i++)
    {
        for (int j=p2;j<e2;j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}
