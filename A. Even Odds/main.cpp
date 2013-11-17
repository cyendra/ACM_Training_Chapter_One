#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL n,d,k,m;

int main()
{
    cin>>n>>k;
    m=(n+1)/2;
    if (k<=m) d=k*2-1;
    else d=(k-m)*2;
    cout<<d<<endl;
    return 0;
}
