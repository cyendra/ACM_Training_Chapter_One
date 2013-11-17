#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[555];
int n;

int main()
{
    int T;
    int ans;
    cin>>T;
    while (T--)
    {
        cin>>n;
        ans=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int m=n/2+1;
        for (int i=1;i<=n;i++) ans+=abs(a[i]-a[m]);
        cout<<ans<<endl;
    }
    return 0;
}
