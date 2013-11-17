#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int tr[27];
string str;
int a[27];

bool cmp( int a,int b )
{
    return ( a>b );
}

int main()
{
    int n,ans,len;
    while (cin >> str)
    {
        if (str=="END")
        {
            break;
        }
        memset(tr,0,sizeof(tr));
        for (int i=0;i<str.length();i++)
        {
            if ( str[i]=='_' )
            {
                tr[26]++;
            }
            else
            {
                tr[ str[i]-'A' ]++;
            }
        }
        n=0;
        for (int i=0;i<27;i++)
        {
            if ( tr[i]!=0 )
            {
                a[n]=tr[i];
                n++;
            }
        }
        sort(a,a+n,cmp);
        ans=0;
        for (int i=n-1;i>0;i--)
        {
            a[i-1]+=a[i];
            ans+=a[i-1];
            sort(a,a+n,cmp);
        }
        len=str.length();
        if ( n==1 )
        {
            ans=len;
        }
        printf("%d %d %0.1f\n",8*len,ans,8.0*len/ans);
    }
    return 0;
}
