#include <iostream>

using namespace std;

int main()
{
    long long int f[51][2];
    int n;
    f[1][0]=3;
    f[1][1]=0;
    f[2][0]=6;
    f[2][1]=0;
    for (int i=3;i<=50;i++)
    {
        f[i][0]=f[i-1][0]+f[i-1][1]*2;
        f[i][1]=f[i-1][0];
    }

    while ( cin >> n )
    {
        cout << f[n][0] << endl;
    }
    return 0;
}
