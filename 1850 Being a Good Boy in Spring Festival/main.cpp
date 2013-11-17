#include <iostream>

using namespace std;

int main()
{
    int n,ans,mix;
    int a[110];
    while(cin>>n)
    {
        if (n==0) break;
        ans=0;
        mix=0;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            mix=mix^a[i];
        }
        if (mix==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        for (int i=0;i<n;i++)
        {
            if ( a[i]>=(mix^a[i]) )
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
