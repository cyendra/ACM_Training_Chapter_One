#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[111]={0};
int z;
int n,k,t;

int main()
{
    cin>>n>>k>>t;
    z=n*k*t/100;
    for (int i=1;i<=z/k;i++)
    {
        a[i]=k;
    }
    a[z/k+1]=z-(z/k)*k;
    for (int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
