
#include <iostream>
#include <cstring>

using namespace std;

const int OO=1e9;

char s[1111];
char b[1111];
int n;
bool a[1111];


int main()
{
    cin>>n;
    cin>>s;
    b[0]='1';
    for (int i=1;i<n;i++)
    {
        if (b[i-1]=='0')
        {
            b[i]='1';
        }
        else if (b[i-1]=='1')
        {
            b[i]='0';
        }
    }
    b[n]='\0';

    //for (int i=0;i<n;i++) cout<<b[i];cout<<endl;

    int ans=0;
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++)
    {
        if (s[i]!=b[i])
        {
            a[i]=1;
        }
    }

    //for (int i=0;i<n;i++) cout<<a[i];cout<<endl;

    for (int i=0;i<n;i++)
    {
        if (a[i]==1)
        {
            ans++;
        }
    }

    int ret=0;
    memset(a,0,sizeof(a));
    for (int i=0;i<n;i++)
    {
        if (s[i]==b[i])
        {
            a[i]=1;
        }
    }

    //for (int i=0;i<n;i++) cout<<a[i];cout<<endl;

    for (int i=0;i<n;i++)
    {
        if (a[i]==1)
        {
            ret++;
        }
    }
    ans=min(ans,ret);
    cout<<ans<<endl;
    return 0;
}
