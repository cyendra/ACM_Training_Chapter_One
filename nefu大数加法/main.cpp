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
    int n;
    string str;
    int ans[111],tmp[111];
    while (cin>>n)
    {
        memset(ans,0,sizeof(ans));
        memset(tmp,0,sizeof(tmp));
        ans[0]=1;
        for (int i=0;i<n;i++)
        {
            memset(tmp,0,sizeof(tmp));
            cin>>str;
            tmp[0]=str.length();
            for (int i=0;i<str.length();i++)
            {
                tmp[i+1]=str[str.length()-i-1]-'0';
            }
            sum(ans,tmp);
            /*
            for (int i=ans[0];i>=1;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
            */
        }
        for (int i=ans[0];i>=1;i--)
        {
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
