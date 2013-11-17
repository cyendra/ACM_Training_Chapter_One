#include <iostream>

using namespace std;

int main()
{
    int C,n,m;
    cin >> C;
    while (C--)
    {
        cin >> n >> m;
        if ( n%(m+1)>0 )
        {
            cout <<"Grass"<<endl;
        }
        else
        {
            cout <<"Rabbit"<<endl;
        }
    }
    return 0;
}
