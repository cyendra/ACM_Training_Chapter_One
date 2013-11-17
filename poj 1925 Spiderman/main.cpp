#include <iostream>
#include <cstring>

using namespace std;

const int OO=1e9;

int K,n;
long long int x[5001],y[5001];
int f[2001000];

int main()
{
    cin>>K;
    while (K--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i];
        }
        for (int i=0;i<=x[n]*2;i++)
        {
            f[i]=OO;
        }
        f[ x[1] ]=0;
        for (int i=2;i<=n;i++)
        {
            for (int j=x[i]-1;j>=x[1];j--)
            {
                long long int d=(x[i]-j)*(x[i]-j)+(y[i]-y[1])*(y[i]-y[1]);
                if (d>y[i]*y[i]) break;
                f[x[i]*2-j]=min(f[x[i]*2-j], f[j]+1);
            }
        }
        int ans=OO;
        for (int i=x[n];i<=x[n]*2;i++)
        {
            ans=min(ans, f[i]);
        }
        if (ans>=OO) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
