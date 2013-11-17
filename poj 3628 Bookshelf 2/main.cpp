#include <iostream>

using namespace std;

int n,b,m,ans;
bool f[20000001];
int h[30];

int main()
{
    while(cin>>n>>b)
    {
        m=0;
        for (int i=0;i<n;i++)
        {
            cin>>h[i];
            m+=h[i];
        }
        for (int i=0;i<=m;i++) f[i]=false;
        f[0]=true;
        for (int i=0;i<n;i++)
        {
            for (int j=m;j>=h[i];j--)
            {
                if ( f[j-h[i]] ) f[j]=true;
            }
        }
        ans=0;
        for (int i=b;i<=m;i++)
        {
            if ( f[i] )
            {
                ans=i;
                break;
            }
        }
        cout<<ans-b<<endl;
    }
    return 0;
}
