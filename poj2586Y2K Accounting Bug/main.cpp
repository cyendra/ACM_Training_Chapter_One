#include <iostream>

using namespace std;

int main()
{
    long long int s,d,ans;
    while (cin>>s>>d)
    {
        //ssssdssssdss
        if (d>4*s)
        {
            ans=10*s-2*d;
        }
        //sssddsssddss
        else if (2*d>3*s)
        {
            ans=8*s-4*d;
        }
        //ssdddssdddss
        else if (3*d>2*s)
        {
            ans=6*s-6*d;
        }
        //sddddsddddsd
        else if (4*d>s)
        {
            ans=3*s-9*d;
        }
        //dddddddddddd
        else
        {
            ans=-1;
        }
        if (ans<0)
        {
            cout<<"Deficit"<<endl;
        }
        else
        {
            cout<<ans<<endl;
        }
    }
    return 0;
}
