#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int a[50];
bool f[1000][1000];

int ans,sum,m;

int area(int x,int y,int z)
{
    double p;
    p=(x+y+z)/2.0;
    return int(sqrt(p*(p-x)*(p-y)*(p-z))*100);
}

int main()
{
    while (cin>>n)
    {
        sum=0;
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        m=sum/2-((sum&1)==0);
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int k=0;k<n;k++)
        {
            for (int i=m;i>=0;i--)
            {
                for (int j=i;j>=0;j--)
                {
                    if (f[i][j])
                    {
                        f[i][j+a[k]]=1;
                        f[i+a[k]][j]=1;
                    }
                }
            }
        }
        ans=-1;
        for (int i=0;i<=m;i++)
        {
            for (int j=0;j<=i;j++)
            {
                if (f[i][j])
                {
                    ans=max( ans , area(i,j,sum-i-j) );
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
