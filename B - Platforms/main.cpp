#include <iostream>

using namespace std;

long long int n,d,m,l;

int main()
{
    long long int ans,k;
    cin>>n>>d>>m>>l;
    k=1;
    ans=0;
    while (k<=n)
    {
        ans+=((k-1)*m+l-ans)/d*d;
        if ( ans+d<k*m ) break;
        k++;
    }
    ans+=d;
    cout<<ans<<endl;
    return 0;
}
