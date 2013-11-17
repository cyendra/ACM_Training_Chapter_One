#include <iostream>

using namespace std;

int a[200];

int main()
{
    bool ok=false;
    int i,j,k,n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            for (k=1;k<=n;k++)
            {
                if (!ok&&i!=j&&j!=k&&i!=k)
                {
                    if (a[i]==a[j]+a[k])
                    {
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        ok=true;
                        break;
                    }
                }
            }
        }
    }
    if (!ok) cout<<"-1"<<endl;
    return 0;
}
