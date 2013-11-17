#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[1000];

int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int mi,ans;
    mi=a[0];
    ans=20124563;
    for (int i=1;i<n;i++)
    {
        if (a[i]!=mi)
        {
            ans=a[i];
            break;
        }
    }
    if (ans!=20124563)
    {
        cout<<ans;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
