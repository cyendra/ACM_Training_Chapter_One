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
    int dot,t;
    bool hdot;
    int a[111],b[111],c[222];
    while (cin>>stra)
    {
        cin>>strb;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        hdot=false;
        dot=0;
        t=a[0]=stra.length()-1;
        for (int i=0;i<stra.length();i++)
        {
            if (stra[i]=='.') hdot=true;
            else
            {
                a[t--]=stra[i]-'0';
                if (hdot) dot++;
            }
        }
        hdot=false;
        t=b[0]=strb.length()-1;
        for (int i=0;i<strb.length();i++)
        {
            if (strb[i]=='.') hdot=true;
            else
            {
                b[t--]=strb[i]-'0';
                if (hdot) dot++;
            }
        }
        /*
        for (int i=a[0];i>=1;i--)
        {
            cout<<a[i];
        }
        cout<<endl;
        for (int i=b[0];i>=1;i--)
        {
            cout<<b[i];
        }
        cout<<endl;
        cout<<dot<<endl;
        */
        mix(a,b,c);
        for (int i=c[0];i>=1;i--)
        {
            if (i==dot) cout<<".";
            cout<<c[i];
        }
        cout<<endl;
    }
    return 0;
}
