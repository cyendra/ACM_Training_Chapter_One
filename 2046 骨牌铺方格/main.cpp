#include <iostream>

using namespace std;

int main()
{
    long long int f[51];
    int n;
    f[0]=1;
    f[1]=1;
    f[2]=2;
    for (int i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    while ( cin >> n )
    {
        cout << f[n] << endl;
    }
    return 0;
}
