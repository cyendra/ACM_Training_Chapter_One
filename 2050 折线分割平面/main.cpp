#include <iostream>

using namespace std;

int main()
{
    int n;
    int t;
    long long int ans;
    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        ans=2*n*n-n+1;
        cout << ans <<endl;
    }
    return 0;
}
