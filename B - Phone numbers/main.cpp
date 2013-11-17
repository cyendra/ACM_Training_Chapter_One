#include <iostream>

using namespace std;

int main()
{
    int n,t;
    string str;
    bool flag;
    int a[200];
    cin>>n;
    cin>>str;
    for (int i=0;i<n;i++)
    {
        a[i]=str[i]-'0';
    }
    if (n&1) flag=true;
    else flag=false;
    t=0;
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
        t++;
        if (flag&&(i!=n-1))
        {
            if (t%3==0)
            {
                cout<<"-";
                flag=false;
                t=0;
            }
        }
        else if (i!=n-1)
        {
            if (t%2==0)
            {
                cout<<"-";
                t=0;
            }
        }
    }
    cout<<endl;
    return 0;
}
