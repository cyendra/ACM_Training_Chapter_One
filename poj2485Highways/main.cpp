#include <iostream>
#include <cstring>
#define OO 9999999

using namespace std;

int d[555];
bool v[555];
int a[555][555];

int main()
{
    int n,t,ans,mind;
    int T;
    cin>>T;
    while (T--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
            d[i]=OO;
            v[i]=false;
        }
        for (int i=1;i<=n;i++)
        {
            d[i]=a[1][i];
        }
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
            if (mind>ans) ans=mind;
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
