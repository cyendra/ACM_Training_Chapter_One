#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[101][101];
int sum[101];
int f[101];
int main()
{
    int n,ans;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin >> a[i][j];
            }
        }
        ans=0;
        //ÎÞµÐsum
        for (int i=0;i<n;i++)
        {
            memset(sum,0,sizeof(sum));
            for (int j=i;j<n;j++)
            {
                for (int k=0;k<n;k++)
                {
                    sum[k]+=a[j][k];
                }
                f[0]=sum[0];
                for (int k=1;k<n;k++)
                {
                    f[k]=max( sum[k] , f[k-1]+sum[k] );
                    if (f[k]>ans)
                    {
                        ans=f[k];
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
