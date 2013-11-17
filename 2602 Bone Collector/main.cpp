#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int T;
int n,m;
int w[1100];
int v[1100];
int f[1100];

int main()
{
    cin >> T;
    while ( T-- )
    {
        cin >> n >> m;
        memset(w,0,sizeof(w));
        memset(v,0,sizeof(v));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            cin >> v[i];
        }
        for (int i=1;i<=n;i++)
        {
            cin >> w[i];
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=m;j-w[i]>=0;j--)
            {
                f[j]=max( f[j] , f[j-w[i]]+v[i] );
            }
        }
        cout << f[m] << endl;
    }
    return 0;
}
