#include <iostream>

using namespace std;

int main()
{
    long long int f[41];
    int n,t;
    f[0]=0;
    f[1]=1;
    f[2]=1;
    f[3]=2;
    for (int i=4;i<=40;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> n;
        cout << f[n] <<endl;
    }
    return 0;
}
