#include <iostream>
#include <cstring>
using namespace std;

int T,n,m,year,tmp;
int v[20],b[20];
int f[111111];

int main()
{
    cin>>T;
    while (T--)
    {
        cin>>m>>year;
        cin>>n;
        for (int i=0;i<n;i++)
        {
            cin>>v[i]>>b[i];
            v[i]=v[i]/1000;
        }
        for (int lp=0;lp<year;lp++)
        {
            tmp=m/1000;
            memset(f,0,sizeof(f));
            for (int k=0;k<n;k++)
            {
                for (int i=v[k];i<=tmp;i++)
                {
                    f[i]=max( f[i] , f[i-v[k]]+b[k] );
                }
            }
            m+=f[tmp];
        }
        cout<<m<<endl;
    }
    return 0;
}
