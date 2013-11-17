#include <iostream>

using namespace std;

long long int a[100][100];

int main()
{
    int n,m;
    for (int i=0;i<=65;i++)
    {
        a[i][0]=a[i][i]=1;
        for (int j=0;j<=i;j++)
        {
            a[i+1][j+1]=a[i][j+1]+a[i][j];
        }
    }
    while (cin>>n>>m)
    {
        cout<<a[n][m]<<endl;
    }
    return 0;
}
