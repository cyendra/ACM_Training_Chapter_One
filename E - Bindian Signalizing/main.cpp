#include <iostream>

using namespace std;

const int mm=1111111;
int a[mm],q[mm];
int i,j,l,n;
long long r,ans;

int main()
{
    while ( cin>>n )
    {
        l=0;
        for (i=0;i<n;i++)
        {
            cin>>a[i];
            if (a[i]>a[l]) l=i;
        }
        ans=r=0;
        q[0]=a[l];
        for (i=l+1;(i%n)!=l;i++)
        {
            j=1;
            while ( r>0&&a[i%n]>q[r] )
            {
                ans+=j;
                if (q[r-1]==q[r])j++;
                else j=1;
                r--;
            }
            r++;
            q[r]=a[i%n];
            ans++;
        }
        j=1;
        while (r>1&&a[l]>q[r])
        {
            ans+=j;
            if (q[r-1]==q[r]) j++;
            else j=1;
            r--;
        }
        if (r>1)
        {
            ans++;
            ans=ans+r*(r+1)/2-r-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
