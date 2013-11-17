#include <iostream>

using namespace std;

int a[100][100];

int main()
{
    int n;
    for (int i=0;i<=50;i++)
    {
        a[i][0]=a[i][i]=1;
        for (int j=0;j<=i;j++)
        {
            a[i+1][j+1]=a[i][j+1]+a[i][j];
        }
    }
    while (cin>>n)
    {
        cout<<a[n][n-4]<<endl;
    }
    return 0;
}
