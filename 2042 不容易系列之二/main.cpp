#include <iostream>

using namespace std;

int main()
{
    long long int f[31];
    int t,n;
    f[0]=3;
    for (int i=1;i<=30;i++)
    {
        f[i]=(f[i-1]-1)*2;
    }
    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        cout << f[n] << endl ;
    }
    return 0;
}
