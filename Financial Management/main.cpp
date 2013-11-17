#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sum,t;
    sum=0;
    for (int i=1;i<=12;i++)
    {
        cin>>t;
        sum+=t;
    }
    sum/=12;
    cout<<"$";
    cout<<fixed;
    cout<<setprecision(2)<<sum<<endl;
    return 0;
}
