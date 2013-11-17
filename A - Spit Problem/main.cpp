#include <iostream>
#include <cstring>

using namespace std;

int a[100000];
int x[200];
int d[200];

int main()
{
    int n,m,t;
    bool ok;
    ok=false;
    m=50000;
    memset(a,0,sizeof(a));
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>d[i];
        a[ m+x[i] ]=i;
    }
    for (int i=0;i<n;i++)
    {
        t=a[ m+x[i]+d[i] ];
        if ( t>0 && a[ m+x[t]+d[t] ]==i )
        {
            ok=true;
            break;
        }
    }
    if (ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
