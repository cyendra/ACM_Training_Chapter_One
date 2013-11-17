#include <iostream>

using namespace std;

int n,x,y,z;
int a,b,c;

int main()
{
    cin>>n;
    cin>>a>>b>>c;
    for (int i=1;i<=n-1;i++)
    {
        cin>>x>>y>>z;
        a+=x;
        b+=y;
        c+=z;
    }
    if (a==0&&b==0&&c==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
