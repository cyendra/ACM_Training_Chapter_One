#include <iostream>

using namespace std;

int main()
{
    int T,n,ans;
    cin>>T;
    while (T--)
    {
        cin>>n;
        if (n>2)cout<<n-2<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
