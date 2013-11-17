#include <iostream>

using namespace std;

int n,L;
int fib[200000]={0,1,1,2,3,5};
int md;

bool getfib(int p)
{
    fib[p]=(fib[p-1]+fib[p-2])%md;
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
    int p=2;
    while (cin>>md)
    {
       p=2;
       fib[0]=0;
       fib[1]=1;
       fib[2]=1;
       while ( !getfib(p) ) p++;
       cout<<L<<endl;
    }
    return 0;
}
