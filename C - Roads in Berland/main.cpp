#include <iostream>

using namespace std;

long long int n,K,e,v,t,ans;
long long int a[500][500];
long long int d[500][500];

int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            d[i][j]=a[i][j];
        }
    }
    for (int k=1;k<=n;k++)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
    }
    cin>>K;
    while (K--)
    {
        ans=0;
        cin>>e>>v>>t;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                if (d[i][j]>d[i][e]+t+d[v][j])
                {
                    d[j][i]=d[i][j]=d[i][e]+t+d[v][j];
                }
                if (d[i][j]>d[i][v]+t+d[e][j])
                {
                    d[j][i]=d[i][j]=d[i][v]+t+d[e][j];
                }
            }
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
            {
                ans+=d[i][j];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
