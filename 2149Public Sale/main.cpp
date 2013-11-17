#include <iostream>

using namespace std;

int main()
{
    int n,m;
    while (cin>>m>>n)
    {
        if ( m%(n+1)>0 )
        {
            if ( m/(n+1)>0 )
            {
                cout << m%(n+1) << endl;
            }
            else
            {
                for (int i=m;i<n;i++)
                {
                    cout << i<<" ";
                }
                cout << n << endl;
            }
        }
        else
        {
            cout<<"none"<<endl;
        }
    }
    return 0;
}
