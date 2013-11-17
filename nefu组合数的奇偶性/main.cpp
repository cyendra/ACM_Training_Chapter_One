#include <iostream>

using namespace std;

int main()
{
    long long int n,k;
    while (cin>>n>>k)
    {
        //cout<<n<<k<<endl;
        if ((n&k)==k)
        {
            cout<<"ODD"<<endl;
        }
        else
        {
            cout<<"EVEN"<<endl;
        }
    }
    return 0;
}
