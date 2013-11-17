#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[1000011];
long int s[1000011];
long int b[1000011];
long sum;
int ans;
int main()
{
    sum=0;
    ans=0;
    memset(s,0,sizeof(s));
    memset(b,0,sizeof(b));
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for (int i=n;i>=1;i--)
    {
        b[i]=b[i+1]+a[i];
    }
    for (int i=1;i<n;i++)
    {
        if ( s[i]==b[i+1] )
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
