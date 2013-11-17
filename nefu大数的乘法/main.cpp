#include <iostream>
#include <cstring>
using namespace std;

void mix(int *a,int b,int *c)
{
    int len;
    len=a[0];
    for (int i=1;i<=len;i++)
    {
        c[i]=a[i]*b;
    }
    for (int i=1;i<=len+len;i++)
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
        if (c[i+1]!=0)
        {
            len=i+1;
        }
    }
    c[0]=len;
}

int main()
{
    string str;
    int a[200];
    int b;
    int c[200];
    while (cin>>str>>b)
    {
        if (b==0)
        {
            cout<<0<<endl;
            continue;
        }
        memset(c,0,sizeof(c));
        memset(a,0,sizeof(a));
        a[0]=str.length();
        for (int i=0;i<str.length();i++)
        {
            a[i+1]=str[str.length()-i-1]-'0';
        }
        mix(a,b,c);
        for (int i=c[0];i>=1;i--)
        {
            cout<<c[i];
        }
        cout<<endl;
    }

    return 0;
}
