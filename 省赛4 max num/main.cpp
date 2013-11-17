#include <iostream>

using namespace std;

int main()
{
    int f[100001],a[100001],st[100001];
    int t,n,max,ans;
    cin >> t;
    for (int loop=0; loop<t; loop++)
    {
        if (loop!=0)
        {
            cout << endl;
        }
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        f[0]=a[0];
        st[0]=0;
        for (int i=1; i<n; i++)
        {
            if (f[i-1]<0)
            {
                f[i]=a[i];
                st[i]=i;
            }
            else
            {
                f[i]=f[i-1]+a[i];
                st[i]=st[i-1];
            }
        }
        max=f[0];
        ans=0;
        for (int i=1; i<n; i++)
        {
            if (f[i]>max)
            {
                max=f[i];
                ans=i;
            }
        }
        cout <<"Case "<<loop+1<<":"<<endl;
        cout <<max<<" "<<st[ans]+1<<" "<<ans+1<<endl;
    }
    return 0;
}
