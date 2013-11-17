#include <iostream>

using namespace std;

int main()
{
    int n,j;
    bool ok;
    while (cin >>n)
    {
        ok=false;
        for (int i=2;i<n;i+=2)
        {
           j=n-i;
           if (j%2==0)
           {
                ok=true;
                break;
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

    }
    return 0;
}
