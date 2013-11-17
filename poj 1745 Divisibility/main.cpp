#include <iostream>
#include <cstring>
using namespace std;

int n,k;
int a[11111];
bool f[2][111];
int g1,g2;

inline int get(int t){ return (t<0)?((-t)%k):(t%k);}

int main()
{
    while (cin>>n>>k)
    {
        for (int i=1;i<=n;i++) cin>>a[i];
        memset(f,0,sizeof(f));
        f[0][ get(a[1]) ]=1;
        g1=1;
        g2=0;
        for (int i=2;i<=n;i++)
        {
            g1=!g1;
            g2=!g2;
            for (int j=0;j<=k;j++)f[g2][j]=0;
            for (int j=0;j<k;j++)
            {
                if (f[g1][j])
                {
                    f[g2][get(j+a[i])]=1;
                    f[g2][get(j-a[i])]=1;
                }
            }
        }
        if (f[g2][0])
        {
            cout<<"Divisible"<<endl;
        }
        else
        {
            cout<<"Not divisible"<<endl;
        }
    }
    return 0;
}
