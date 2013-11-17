#include <iostream>
#include <cstring>

using namespace std;

int n,m;

int w[4000];
int d[4000];
int f[20000];

int main()
{
    while (cin>>n>>m)
    {
        for (int i=1;i<=n;i++)
        {
            cin>>w[i]>>d[i];
        }
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
        {
            for (int j=m;j>=w[i];j--)
            {
                f[j]=max( f[j] , f[j-w[i]]+d[i] );
            }
        }
        cout<<f[m]<<endl;
    }
    return 0;
}
