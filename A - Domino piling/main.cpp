#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin>>m>>n;
    int x=m/2;
    int ans=x*n;
    if (m%2==1)
    {
        int y=n/2;
        ans+=y;
    }
    cout<<ans<<endl;
    return 0;
}
