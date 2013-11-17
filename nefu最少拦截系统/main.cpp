
#include <iostream>
#include <cstring>
#define MAXN 50000

using namespace std;

int a[MAXN];
int f[MAXN];
int n;

int main()
{
    int max;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
            f[i]=1;
        }
        for (int i=0;i<n;i++)
        {
            //f[i]=n-1;
            for (int j=0;j<i;j++)
            {
                if ( a[i]>a[j] && f[j]+1>f[i] )
                {
                    f[i]=f[j]+1;
                }
            }
        }
        max=0;
        for (int i=0;i<n;i++)
        {
            if ( f[i]>max )
            {
                max=f[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
