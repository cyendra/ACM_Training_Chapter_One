#include <iostream>
#include <cstdio>
using namespace std;

bool v[100011];

int main()
{
    int n,t;
    bool ok;
    v[0]=true;
    v[1]=true;
    for (int i=2;i<=100000;i++)
    {
        if (!v[i])
        {
            for (int j=i+i;j<=100000;j+=i)
            {
                v[j]=true;
            }
        }
    }
    while (cin>>n)
    {
        if ( !v[n] )
        {
            ok=true;
            for (int i=10000;i>1;i=i/10)
            {
                t=n/i;
                if (t==0) continue;
                n=n-t*i;
                if (v[n])
                {
                    ok=false;
                    break;
                }
            }
            if (ok) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
