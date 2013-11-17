#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    int s;
    while (cin>>n>>m)
    {
        s=0;
        s=n+m-1;
        cout<<s<<endl;
        for (int i=1;i<=m;i++) cout<<"1 "<<i<<endl;
        for (int i=2;i<=n;i++) cout<<i<<" 1"<<endl;
    }
    return 0;
}
