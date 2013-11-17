#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int a[10001];
double b[10001];
double f[10001];

int main()
{
    int n,m;
    double ans;
    while (cin >> n >> m)
    {
        if (n==0 && m==0)
        {
            break;
        }
        for (int i=0;i<m;i++)
        {
            cin >> a[i] >> b[i];
        }
        for (int i=0;i<=n;i++)
        {
            f[i]=0;
        }
        for (int i=0;i<m;i++)
        {
            for (int j=n;j>=a[i];j--)
            {
                if ( (f[j-a[i]]+b[i])-( f[j-a[i]]*b[i] ) >f[j] )
                {
                    f[j]=(f[j-a[i]]+b[i])-( f[j-a[i]]*b[i] );
                }
            }
        }
        printf("%0.1f%%\n",f[n]*100);
    }
    return 0;
}
