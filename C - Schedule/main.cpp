#include <iostream>

using namespace std;

int n;
int l[6000],r[6000];
int a[6000]={0};
int num,ans;

int main()
{
    num=0;
    ans=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (l[i]<r[j]&&l[j]<r[i])
            {
                a[i]++;
                a[j]++;
                num++;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]==num)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==num)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    return 0;
}
