#include <iostream>
#include <cmath>

using namespace std;

double n,p;

int main()
{
    while (cin>>n>>p)
    {
        cout<<pow(p,1/n)<<endl;
    }
    return 0;
}
