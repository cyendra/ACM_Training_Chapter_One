#include <iostream>

using namespace std;

const int INF=1e9;

int f[4444];
int n,m;
int a[4];

int main()
{
    cin>>n>>a[0]>>a[1]>>a[2];
    for (int i=1;i<=n;i++) f[i]=-INF;
    f[0]=0;
    for (int i=0;i<=2;i++)
    {
        for (int j=0;j<=n-a[i];j++)
        {
            if (f[j]!=-INF)
            {
                f[j+a[i]]=max(f[j+a[i]],f[j]+1);
            }
        }
    }
    cout<<f[n]<<endl;
    return 0;
}
