#include <iostream>
#include <cstring>
using namespace std;

int a[100010];
int p[100010];
int n,t;


int main()
{
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    p[1]=1;
    t=1;
    for (int i=2; i<=n; i++)
    {
        if (a[i]!=a[t])
        {
            t++;
            a[t]=a[i];
            p[t]=i;
        }
    }
    if (t<3)
    {
        cout<<"0"<<endl;
    }
    else
    {
        for (int i=2; i<t; i++)
        {
            if (a[i-1]<a[i]&&a[i]>a[i+1])
            {
                cout<<"3"<<endl;
                cout<<p[i-1]<<" "<<p[i]<<" "<<p[i+1]<<endl;
                return 0;
            }
            else if (a[i-1]>a[i]&&a[i]<a[i+1])
            {
                cout<<"3"<<endl;
                cout<<p[i-1]<<" "<<p[i]<<" "<<p[i+1]<<endl;
                return 0;
            }
        }
        cout<<"0"<<endl;
    }

    return 0;
}
