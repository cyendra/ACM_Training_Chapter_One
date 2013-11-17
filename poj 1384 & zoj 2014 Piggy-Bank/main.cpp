#include <iostream>
#define OO 99999999

using namespace std;

int E,F,m,n,T;
int v[555],w[555];
int f[111111];

int main()
{
    cin>>T;
    while (T--)
    {
        cin>>E>>F;
        m=F-E;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>v[i]>>w[i];
        }
        for (int i=0;i<=m;i++) f[i]=OO;
        f[0]=0;
        for (int k=0;k<n;k++)
        {
            for (int i=w[k];i<=m;i++)
            {
                f[i]=min( f[i] , f[i-w[k]]+v[k] );
            }
        }
        if ( f[m]<OO )
        {
            cout<<"The minimum amount of money in the piggy-bank is "<<f[m]<<"."<<endl;
        }
        else
        {
            cout<<"This is impossible."<<endl;
        }
    }
    return 0;
}
