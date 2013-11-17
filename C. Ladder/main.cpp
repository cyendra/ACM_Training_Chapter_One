#include <iostream>

using namespace std;

int n,m;

int a[111111]={0};
int f[111111]={0};

bool flag;
int tmp;
int l,r;

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    flag=false;
    f[1]=1;
    for (int i=2;i<=n;i++)
    {
        if ( flag && a[i]>=a[i-1] )
        {
            f[i]=f[i-1];
        }
        else if ( flag && a[i]<a[i-1] )
        {
            flag=true;
            f[i]=f[i-1];
        }
        else if ( !flag && a[i]<=a[i-1] )
        {
            f[i]=f[i-1];
        }
        else if ( !flag && a[i]>a[i-1] )
        {
            f[i]=i;
            tmp=i;
            while ( tmp>=2 && a[tmp]>a[tmp-1] )
            {
                tmp=tmp-1;
            }
            f[i]=tmp;
        }
    }
    while (m--)
    {
        cin>>l>>r;
        if ( f[r]<=l ) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
