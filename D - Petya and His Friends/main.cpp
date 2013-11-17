#include <iostream>

using namespace std;

long long n;

int main()
{
    cin>>n;
    if (n<3) cout<<-1<<endl;
    else
    {
        cout<<6<<endl;
        cout<<10<<endl;
        cout<<15<<endl;
        n-=3;
        unsigned long long t=6;
        while (n--)
        {
            t=t<<1;
            cout<<t<<endl;
        }
    }
    return 0;
}
