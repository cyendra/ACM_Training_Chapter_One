#include <iostream>

using namespace std;

int main()
{
    int a,b,n,x;
    cin>>a>>b>>n;
    for (int i=-10000;i<=10000;i++)
    {
        x=i;
        for (int j=1;(j<n)&&(x<10000);j++) x*=i;
        if ( a*x==b )
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"No solution"<<endl;
    return 0;
}
