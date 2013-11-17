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
        for (int i=0;i<m;i++)
        {
            cin>>t;
            ans+=t;
        }
        cout<<ans<<endl;
        if (n!=0)cout<<endl;
    }
    return 0;
}
