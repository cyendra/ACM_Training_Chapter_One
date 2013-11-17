#include <iostream>

using namespace std;

int n;
int t;

int main()
{
    cin>>n;
    t=1;
    for (int i=1;i<n;i++)
    {
        t=(3*t)%(1000003);
    }
    cout<<t<<endl;
    return 0;
}
