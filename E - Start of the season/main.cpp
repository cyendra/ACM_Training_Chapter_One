#include <iostream>
#include <cstring>
using namespace std;

int a[1010][1010];
int n;

int main()
{
    cin >> n;
    memset(a,-1,sizeof(a));
    for (int i=0;i<n;i++)
    {
        a[i][i]=0;
    }
    for (int num=n-1;num>0;num--)
    {
        for (int i=0;i<=num;i++)
        {
            if ( a[i][n-1-i]==-1 ) a[i][n-1-i]=num;
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            a[n-1-j][n-1-i]=a[i][j];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}











