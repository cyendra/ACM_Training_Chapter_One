#include <iostream>

using namespace std;

int n,k;
int a[2000],d[2000];
bool f[111111];
int m;

void ZeroOnePack(int v)
{
    for (int i=m-v; i>=0; i--)
    {
        if (f[i]) f[i+v]=1;
    }
}
void CompletePack(int v)
{
    for (int i=0; i<=m-v; i++)
    {
        if (f[i]) f[i+v]=1;
    }
}

int main()
{
    while (cin>>m>>n)
    {
        for (int i=0; i<n; i++)
        {
            cin>>a[i]>>d[i];
        }
        for (int i=0; i<=m; i++) f[i]=0;
        f[0]=1;
        for (int i=0; i<n; i++)
        {
            if ( a[i] )
            {
                if ( d[i]*a[i]>=m )
                {
                    CompletePack(d[i]);
                }

                else
                {
                    k=1;
                    while (k<a[i])
                    {
                        ZeroOnePack(d[i]*k);
                        a[i]-=k;
                        k<<=1;
                    }
                    ZeroOnePack(d[i]*a[i]);
                }

            }
        }
        while (!f[m]) m--;
        cout<<m<<endl;
    }
    return 0;
}
