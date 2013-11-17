#include <iostream>

using namespace std;

int main()
{
    long long int f[30],n;
    f[0]=0;
    f[1]=0;
    f[2]=1;
    f[3]=2;
    for (int i=4; i<=20; i++)
    {
        f[i]=(i-1)*( f[i-1]+f[i-2] );
    }
    while ( cin >> n )
    {
        cout << f[n]<<endl;
    }
    return 0;
}
