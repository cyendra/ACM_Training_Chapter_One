#include <iostream>
#include <algorithm>

using namespace std;

int a[1010];
int b[1010];
int n;
int ans;
int lowb,highb,lowa,higha;

int main()
{
    while (cin>>n &&n!=0)
    {
        for (int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        for (int i=0;i<n;i++)
        {
            cin >> b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        lowa=0;
        lowb=0;
        higha=n-1;
        highb=n-1;
        ans=0;
        for (int round=0;round<n;round++)
        {
            if ( a[higha]>b[highb] )
            {
                higha--;
                highb--;
                ans+=200;
            }
            else if ( a[higha]<b[highb] )
            {
                lowa++;
                highb--;
                ans-=200;
            }
            else if ( a[higha]==b[highb] )
            {
                if ( a[lowa]>b[lowb] )
                {
                    lowa++;
                    lowb++;
                    ans+=200;
                }
                else if ( a[lowa]<b[lowb] )
                {
                    lowa++;
                    highb--;
                    ans-=200;
                }
                else if ( a[lowa]==b[lowb] )
                {
                    if ( a[lowa]<b[highb] )
                    {
                        lowa++;
                        highb--;
                        ans-=200;
                    }
                    else
                    {
                        lowa++;
                        highb--;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
