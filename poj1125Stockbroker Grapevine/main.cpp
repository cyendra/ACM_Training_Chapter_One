#include <iostream>
#define OO 999999

using namespace std;

int a[200][200];
int n;

int main()
{
    int x,y,t;
    int ans,max,min;
    while (cin>>n)
    {
        if (n==0) break;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                a[i][j]=OO;
            }
        }
        for (int i=1;i<=n;i++)
        {
            cin>>x;
            for (int j=1;j<=x;j++)
            {
                cin>>y>>t;
                a[i][y]=t;
            }
        }
        for (int k=1;k<=n;k++)
        {
            for (int i=1;i<=n;i++)
            {
                for (int j=1;j<=n;j++)
                {
                    if (a[i][k]+a[k][j]<a[i][j])
                    {
                        a[i][j]=a[i][k]+a[k][j];
                    }
                }
            }
        }
        min=OO;
        for (int i=1;i<=n;i++)
        {
            max=-OO;
            for (int j=1;j<=n;j++)
            {
                if (i!=j&&a[i][j]>max)
                {
                    max=a[i][j];
                }
            }
            if (max<min)
            {
                min=max;
                ans=i;
            }
        }
        cout<<ans<<" "<<min<<endl;
    }
    return 0;
}
