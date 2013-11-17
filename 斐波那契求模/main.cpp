#include <iostream>

using namespace std;

int n,L;
int fib[2000]={0,1,1,2,3,5};

bool getfib(int p)
{
    fib[p]=(fib[p-1]+fib[p-2])%103;
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
    while ( !getfib(p) ) p++;
    //cout<<L<<endl;
    while (cin>>n)
    {
        cout<<fib[ n%L ]%103<<endl;
    }
    return 0;
}
