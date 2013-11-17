#include <iostream>

using namespace std;

int T,n,c1,c2,s;
int a[11],g[1111],f[1111];
bool v[111];
bool ok(int x);

bool ok(int x)
{
    int sum=0;
    for (int i=0;i<=c1;i++) v[i]=0;
    v[0]=1;
    for (int i=0;i<n;i++)
    {
        if (x&(1<<i))
        {
            sum+=a[i];
            for (int j=c1-a[i];j>=0;j--)
            {
                if (v[j])v[j+a[i]]=1;
            }
        }
    }
    for (int i=c1;i>=0;i--)
    {
        if (v[i]&&sum-i<=c2) return true;
    }
    return false;
}

int main()
{
    cin>>T;
    for (int lp=1;lp<=T;lp++)
    {
        cin>>n>>c1>>c2;
        if (c1>c2) swap(c1,c2);
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        s=0;
        for (int i=0;i<(1<<n);i++)
        {
            if (ok(i)) g[s++]=i;
        }
        for (int i=0;i<(1<<n);i++)
        {
            f[i]=1000000000;
        }
        f[0]=0;
        for (int i=0;i<s;i++)
        {
            for (int j=(1<<n)-1;j>=0;j--)
            {
                if ( !(j&g[i]) )
                {
                    f[j|g[i]]=min( f[j|g[i]] , f[j]+1 );
                }
            }
        }
        cout<<"Scenario #"<<lp<<":"<<endl;
        cout<<f[ (1<<n)-1 ]<<endl;
        cout<<endl;
    }
    return 0;
}
