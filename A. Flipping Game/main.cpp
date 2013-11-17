#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF=1e9;
int a[111]={0};
int f[111]={0};
int n;

int main()
{
    int ans;
    int bas;
    while (cin>>n)
    {
        ans=-INF;
        bas=0;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            if (a[i]) {a[i]=-1; bas++; }
            else if (!a[i]) a[i]=1;
        }
        for (int i=1;i<=n;i++)
        {
            f[i]=max(f[i-1]+a[i],a[i]);
            ans=max(ans,f[i]);
        }
        cout<<bas+ans<<endl;
    }
    return 0;
}
