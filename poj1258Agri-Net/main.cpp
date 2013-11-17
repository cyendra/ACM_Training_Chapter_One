#include <iostream>
#include <cstring>
#define OO 999999
using namespace std;

int a[200][200];
int d[200];
bool v[200];
int n;

int main()
{
    int ans,mind,t;
    while (cin>>n)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
            d[i]=OO;
            v[i]=false;
        }
        d[1]=0;
        ans=0;
        for (int loop=1;loop<=n;loop++)
        {
            mind=OO;
            for (int i=1;i<=n;i++)
            {
                if (!v[i]&&d[i]<mind)
                {
                    mind=d[i];
                    t=i;
                }
            }
            v[t]=true;
            ans+=mind;
            for (int i=1;i<=n;i++)
            {
                if (a[t][i]<d[i])
                {
                    d[i]=a[t][i];
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
