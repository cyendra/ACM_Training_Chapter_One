/*
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a[510];
int b[510];
int f[501][501];
int n,k;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    k=1;
    for (int i=1;i<=n;i++)
    {
        if (b[i]!=b[k])
        {
            k++;
            b[k]=b[i];
        }
    }
    k++;
    //-------------------------------------------------
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            if (i==1&&j==1)
            {
                f[1][1]=abs( a[1]-b[1] );
            }
            else if (i==1&&j>1)
            {
                f[1][j]=min( f[1][j-1] , abs(a[1]-b[j]) );
            }
            else if (i>1&&j==1)
            {
                f[i][1]=f[i-1][1]+abs(a[i]-b[1]);
            }
            else if (i>1&&j>1)
            {
                f[i][j]=min( f[i][j-1] , f[i-1][j]+abs(a[i]-b[j]) );
            }
        }
    }
    cout << f[n][k] << endl;
    return 0;
}

*/

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int a[510];
int b[510];
int f[501][501];
int n,k;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    //-------------------------------------------------
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (i==1&&j==1)
            {
                f[1][1]=abs( a[1]-b[1] );
            }
            else if (i>1&&j>1)
            {
                f[i][j]=min( f[i][j-1] , f[i-1][j]+abs(a[i]-b[j]) );
            }
        }
    }
    cout << f[n][n] << endl;
    return 0;
}
