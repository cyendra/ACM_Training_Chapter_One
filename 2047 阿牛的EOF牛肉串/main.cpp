#include <iostream>

using namespace std;

int main()
{
    long long int f[40][2];
    int n;

    f[1][0]=1;
    f[1][1]=2;
    f[2][0]=2;
    f[2][1]=6;
    for (int i=3;i<40;i++)
    {
        f[i][0]=f[i-1][1];
        f[i][1]=(f[i-1][0]+f[i-1][1])*2;
    }

    while ( cin >> n )
    {
        cout << f[n][0]+f[n][1] << endl;
    }
    return 0;
}
