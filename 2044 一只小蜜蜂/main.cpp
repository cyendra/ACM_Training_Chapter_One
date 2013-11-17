#include <iostream>

using namespace std;

int main()
{
    long long int f[51];
    int t;
    int a,b,n;
    f[0]=0;
    f[1]=1;
    f[2]=1;
    for (int i=3;i<=50;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cin >> t;
    for (int i=0;i<t;i++)
    {
        cin >> a >> b;
        n=b-a+1;
        cout << f[n] << endl;
    }
    return 0;
}
