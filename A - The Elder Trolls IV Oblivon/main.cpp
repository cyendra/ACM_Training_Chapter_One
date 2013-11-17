#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long x,y,z,k;
long long a[4];

int main()
{
    cin>>a[0]>>a[1]>>a[2]>>k;
    sort(a,a+3);
    if (a[0]>=k/3+1)
    {
        x=k/3+1;
        k-=k/3;
    }
    else
    {
        x=a[0];
        k-=a[0]-1;
    }
    if (a[1]>=k/2+1)
    {
        y=k/2+1;
        k-=k/2;
    }
    else
    {
        y=a[1];
        k-=a[1]-1;
    }
    if (a[2]>=k+1)
    {
        z=k+1;
    }
    else
    {
        z=a[2];
    }
    long long ans=x*y*z;
    cout<<ans<<endl;
    return 0;
}
