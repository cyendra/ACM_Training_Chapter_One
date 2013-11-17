#include <iostream>

using namespace std;

int n,k;
int a[111]={0};
int rank[111]={0};

int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        rank[a[i]]++;
    }
    int ans=0;
    bool ok=true;
    while (ok)
    {
        ok=false;
        for (int i=k-1;i>=1;i--)
        {
            if (rank[i]>0)
            {
                rank[i]--;
                rank[i+1]++;
                ok=true;
            }
        }
        if (ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
