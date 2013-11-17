#include <iostream>
#include <string>
using namespace std;

int a[1111];
int n;
string s;
int h,t;

int main()
{
    cin>>n;
    cin>>s;
    h=t=0;
    for (int i=0; i<n; i++)
    {
        if ( s[i]=='H' ) h++;
        else if ( s[i]=='T' ) t++;
    }
    int ans=9999999;
    int ct=0;
    for (int i=0; i+h<n; i++)
    {
        ct=0;
        for (int j=0; j<h&&i+j<n; j++)
        {
            if ( s[i+j]=='T' ) ct++;
        }
        if (ct<ans) ans=ct;
    }
    for (int i=0; i+t<n; i++)
    {
        ct=0;
        for (int j=0; j<t&&i+j<n; j++)
        {
            if ( s[i+j]=='H' ) ct++;
        }
        if (ct<ans) ans=ct;
    }
    cout<<ans<<endl;
    return 0;
}
