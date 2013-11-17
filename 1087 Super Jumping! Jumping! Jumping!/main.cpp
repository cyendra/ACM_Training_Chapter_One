#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long int n,max;
    long long int a[1001],f[1001];
    while ( cin >> n )
    {
        if (n==0)
        {
            break;
        }
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for (int i=0;i<n;i++)
        {
            f[i]=a[i];
            for (int k=0;k<i;k++)
            {
                if ( (a[i]>a[k])&&( f[i]<f[k]+a[i] ) )
                {
                    f[i]=f[k]+a[i];
                }
            }
        }
        max=0;
        for (int i=0;i<n;i++)
        {
            if (f[i]>max)
            {
                max=f[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
