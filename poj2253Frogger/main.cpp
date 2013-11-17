#include <iostream>
#include <cmath>
#include <iomanip>
#define OO 999999

using namespace std;

double mind;
int n,p;
double a[500][500];
double d[500];
int v[500];
int ax[500];
int ay[500];

int main()
{
    int loop=0;
    cout<<fixed;
    cout<<setprecision(3);
    while (cin>>n)
    {
        if (n==0) break;
        loop++;
        for (int i=0;i<n;i++)
        {
            cin>>ax[i]>>ay[i];
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                a[i][j]=sqrt( (ax[i]-ax[j])*(ax[i]-ax[j])+(ay[i]-ay[j])*(ay[i]-ay[j]) );
            }
        }
        for (int i=0;i<n;i++)
        {
            d[i]=OO;
            v[i]=false;
        }
        d[0]=0;
        for (int i=0;i<n;i++)
        {
            mind=OO;
            for (int j=0;j<n;j++)
            {
                if (!v[j]&&d[j]<mind)
                {
                    mind=d[j];
                    p=j;
                }
            }
            v[p]=true;
            for (int j=0;j<n;j++)
            {
                if (!v[j]&&a[j][p]!=0)
                {
                    if (d[j]>max(a[j][p],d[p]))
                    {
                        d[j]=max(a[j][p],d[p]);
                    }
                }
            }
        }
        cout<<"Scenario #"<<loop<<endl;
        cout<<"Frog Distance = "<<d[1]<<endl;
        cout<<endl;
    }
    return 0;
}
