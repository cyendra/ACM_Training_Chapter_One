/*
#include <iostream>
#include <cstring>

using namespace std;

int a[50000];
int f[50000];
int v[50000];
int n;

int main()
{
    int max;
    while ( cin >> n )
    {
        memset(v,0,sizeof(v));
        max=0;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        for (int i=0; i<n; i++)
        {
            f[i]=1;
            for (int k=0; k<i; k++)
            {
                if ( a[k]>=a[i] && f[k]+1>f[i] )
                {
                    f[i]=f[k]+1;
                }
            }
            v[ f[i] ]++;
        }
        for (int i=1;i<=n;i++)
        {
            if ( v[i]>max )
            {
                max=v[i];
            }
        }
        cout << max << endl;
    }
    return 0;
}
*/
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
