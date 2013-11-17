#include <iostream>

using namespace std;

int main()
{
    int n,m,t,ans;
    cin>>n;
    while (n--)
    {
        cin>>m;
        ans=0;
        for (int i=1;i<=m;i++)
        {
            cin>>t;
            ans+=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
