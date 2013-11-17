#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

const double OO=9999999999999999999999999999999.0;

int n;
double mx[200];
double my[200];
double a[200][200];
double d[200];
bool v[200];

int main()
{

    while(cin>>n)
    {
        memset(v,0,sizeof(v));
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(mx,0,sizeof(mx));
        memset(my,0,sizeof(my));
        for (int i=1; i<=n; i++)
        {
            cin>>mx[i]>>my[i];
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=n; j++)
            {
                a[i][j]=(mx[i]-mx[j])*(mx[i]-mx[j])+(my[i]-my[j])*(my[i]-my[j]);
                a[i][j]=sqrt(a[i][j]);
            }
        }
        double mind,ans;
        int t;
        ans=0;
        for (int i=1; i<=n; i++) d[i]=OO;
        d[1]=0;
        for (int loop=1; loop<=n; loop++)
        {
            mind=OO;
            for (int i=1; i<=n; i++)
            {
                if (!v[i]&&d[i]<mind)
                {
                    mind=d[i];
                    t=i;
                }
            }
            v[t]=true;
            ans+=mind;
            for (int i=1; i<=n; i++)
            {
                if (a[t][i]<d[i])
                {
                    d[i]=a[t][i];
                }
            }
        }
        cout<<fixed;
        cout<<setprecision(2);
        cout<<ans<<endl;
    }
    return 0;
}
