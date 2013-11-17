#include <iostream>

using namespace std;

int a[4000]={0};

int main()
{
    int n,t;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>t;
        a[t]=1;
    }
    for (int i=1;i<=3010;i++)
    {
        if (a[i]==0)
        {
            t=i;
            break;
        }
    }
    cout<<t<<endl;
    return 0;
}
