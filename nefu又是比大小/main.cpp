#include <iostream>
#include <cstring>
using namespace std;

void sum(int *a,int *b)
{
    int len;
    if (a[0]>b[0])
    {
        len=a[0];
    }
    else
    {
        len=b[0];
    }

    for (int i=1;i<=len;i++)
    {
        a[i]=a[i]+b[i];
    }
    a[0]=len;
    for (int i=1;i<=len;i++)
    {
        if (a[i]>9)
        {
            a[i+1]+=a[i]/10;
            a[i]=a[i]%10;
        }
    }
    if (a[len+1]>0)
    {
        a[0]=a[0]+1;
    }
}


int main()
{
    string stra,strb,strc;
    bool ok;
    int a[200],b[200],c[200];
    while(cin>>stra)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        cin>>strb>>strc;
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
        c[0]=strc.length();
        for (int i=0;i<strc.length();i++)
        {
            c[i+1]=strc[strc.length()-i-1]-'0';
        }
        sum(a,b);

        ok=false;
        if (a[0]>c[0])
        {
            ok=true;
        }
        else if (a[0]<c[0])
        {
            ok=false;
        }
        else
        {
            for (int i=a[0];i>=1;i--)
            {
                if (a[i]>c[i])
                {
                    ok=true;
                    break;
                }
                else if (a[i]<c[i])
                {
                    ok=false;
                    break;
                }
            }
        }
        if (ok)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
