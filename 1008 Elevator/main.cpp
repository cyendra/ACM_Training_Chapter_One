#include <iostream>

using namespace std;

int main()
{
    int n;
    int ans;
    int q;
    int now;
    while (cin>>n)
    {
        if (n==0)
        {
            break;
        }
        now=0;
        ans=0;
        for (int i=0; i<n; i++)
        {
            cin>>q;
            if (q>now)
            {
                ans+=(q-now)*6;
                ans+=5;
            }
            else if (q<now)
            {
                ans+=(now-q)*4;
                ans+=5;
            }
            else
            {
                ans+=5;
            }
            now=q;
        }
        cout << ans << endl;
    }
    return 0;
}
