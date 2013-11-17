#include <iostream>

using namespace std;

int n,x,y,p,t;
int a[1111][1111];
int h[1111];
int d[1111][2];

int main()
{
    p=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        h[i]=i;
    }
    for (int i=1;i<=n-1;i++)
    {
        cin>>x>>y;
        if (h[x]==h[y])
        {
            d[p][0]=x;
            d[p][1]=y;
            p++;
        }
        else
        {
            t=h[y];
            for (int j=1;j<=n;j++)
            {
                if (h[j]==t)
                {
                    h[j]=h[x];
                }
            }
        }
    }
    cout<<p<<endl;
    for (int i=0;i<p;i++)
    {
        cout<<d[i][0]<<" "<<d[i][1]<<" "<<h[1]<<" ";
        for (int j=1;j<=n;j++)
        {
            if (h[j]!=h[1])
            {
                cout<<h[j]<<endl;
                t=h[j];
                break;
            }
        }
        for (int j=1;j<=n;j++)
        {
            if (h[j]==t)
            {
                h[j]=h[1];
            }
        }
    }
    return 0;
}
