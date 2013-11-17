#include <iostream>

using namespace std;

int main()
{
    int n,m,C;
    cin >> C;
    while (C--)
    {
        cin >> n >> m;
        if ( n % (m+1)>0 )
        {
            cout << "first" << endl;
        }
        else
        {
            cout << "second" << endl;
        }
    }
    return 0;
}
