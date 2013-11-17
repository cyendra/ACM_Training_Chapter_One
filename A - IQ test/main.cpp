#include <iostream>

using namespace std;

int main()
{
    int n;
    int a[100];
    int ans;
    int fjishu,foushu;
    cin>>n;
    fjishu=foushu=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]&1)
        {
            fjishu++;
        }
        else
        {
            foushu++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if ( fjishu==1 && (a[i]&1) )
        {
            ans=i;
            break;
        }
        else if (foushu==1 && !(a[i]&1) )
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
