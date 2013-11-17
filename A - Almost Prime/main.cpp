#include <iostream>
#include <cstring>
using namespace std;

int f[5010];

int main()
{
    int n,ans;
    ans=0;
    memset(f,0,sizeof(f));
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        for (int j=2;j<i;j++)
        {
            if (f[j]==0&&i%j==0)
            {
                f[i]++;
            }
        }
    }
    for (int i=2;i<=n;i++)
    {
        if (f[i]==2)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
