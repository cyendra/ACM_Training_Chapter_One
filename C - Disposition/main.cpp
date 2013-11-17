#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    if (n%2==1) cout<<1<<" ";
    for (int i=n%2+1;i<=n;i++)
    {
        cout<<i+1<<" "<<i<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}
