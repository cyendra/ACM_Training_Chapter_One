#include <iostream>

using namespace std;

int main()
{
    int n,t,ans;
    while (cin>>n)
    {
        ans=0;
        for (int i=1;i<=n;i++)
        {
            cin>>t;
            ans+=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
