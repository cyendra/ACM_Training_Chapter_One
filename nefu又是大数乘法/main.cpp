#include <iostream>
#include <cstring>

using namespace std;


void mix(int *a,int *b,int *c)
{
    int len;
    for (int i=1;i<=b[0];i++)
    {
        for (int j=1;j<=a[0];j++)
        {
            c[i+j-1]+=b[i]*a[j];
        }
    }
    if (a[0]>b[0]) c[0]=a[0];
    else c[0]=b[0];
    len=c[0];
    for (int i=1;i<=c[0]+c[0];i++)
    {
        c[i+1]+=c[i]/10;
        c[i]=c[i]%10;
        if (c[i+1]>0) len=i+1;
    }
    c[0]=len;
}


int main()
{
    string stra,strb;
    int a[111],b[111],c[111];
    while (cin>>stra>>strb)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        a[0]=stra.length();
        for (int i=0;i<stra.length();i++)
        {
            a[i+1]=stra[stra.length()-i-1]-'0';
        }
        b[0]=strb.length();
        for (int i=0;i<strb.length();i++)
        {
            b[i+1]=strb[strb.length()-i-1]-'0';
        }
        mix(a,b,c);
        for (int i=c[0];i>=1;i--)
        {
            if (i%3==0&&i!=c[0]) cout<<" ";
            cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
