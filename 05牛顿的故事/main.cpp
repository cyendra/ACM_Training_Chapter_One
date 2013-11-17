#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int f[200][3];
    int a[200][3];
    int n,t,ans;
    while (cin >> n)
    {
        memset(f,0,sizeof(f));
        memset(a,0,sizeof(a));
        t=0;
        for (int i=0; i<n; i++)
        {
            cin >> t ;
            cin >> a[t][0] >> a[t][1] >> a[t][2];
            f[t][0]=f[t-1][0]+a[t][0];
            f[t][1]=max(f[t-1][0],f[t-1][1])+a[t][1];
            f[t][2]=max(f[t-1][1],f[t-1][2])+a[t][2];
        }
        ans= max( max(f[t][0],f[t][1])  ,  f[t][2]    );
        cout << ans << endl;
    }
    return 0;
}
