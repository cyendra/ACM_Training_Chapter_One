#include <iostream>

using namespace std;

int n,L;
int fib[2000]={0,1,3,10,33};

bool check(int p)
{
    fib[p]=(3*fib[p-1]+fib[p-2])%223;
    if ( fib[p-1]==0&&fib[p]==1 )
    {
        L=p-1;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int p=5;

    while (!check(p)) p++;

    while (cin>>n)
    {
        cout<<fib[ n%L ]%223<<endl;
    }
    return 0;
}
