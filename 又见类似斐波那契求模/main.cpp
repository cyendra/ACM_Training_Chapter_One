#include <iostream>

using namespace std;

int a,b,N,L;
int fib[100000]={0,1};

bool getfib(int p)
{
    fib[p]=(a*fib[p-1]+b*fib[p-2])%107;
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
    int p,t;
    while ( cin>>a>>b>>N )
    {
        p=2;
        while ( !getfib(p) ) p++;
        for (int i=0;i<N;i++)
        {
            cin>>t;
            cout<<fib[ t%L ]%107<<endl;
        }
    }
    return 0;
}
