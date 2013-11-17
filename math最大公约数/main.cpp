#include <iostream>
#include <algorithm>

using namespace std;

int n;
long int a[111];

int main()
{
    long int ans,tmp;
    bool ok;
    while (cin>>n)
    {
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        ans=1;
        for (int i=a[0];i>=2;i--)
        {
            ok=true;
            for (int j=0;j<n;j++)
            {
                if (a[j]%i!=0)
                {
                    ok=false;
                    break;
                }
            }
            if (ok)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
