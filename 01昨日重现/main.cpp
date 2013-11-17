#include <iostream>

using namespace std;

int main()
{
    long long int n,ans,tmp,wtf,wrong;
    //wrong=0;
    while (cin >> n)//for (int n=2; n<1000000; n++)
    {
        //tmp=(n*(n+1)*(2*n+1)/6)%1007;
        //tmp=(2*n*n*n)%1007 + ( 3*n*n )%1007 + n%1007;
        //tmp=tmp%1007;
        //ans=(n*(((2*n*n)+3*n+1)))%1007;
        ans=n*(n+1)/2;
        if (ans % 3==0)
        {
            ans=ans/3;
            ans=ans % 1007;
            ans=(ans*((2*n+1)%1007))%1007;
        }
        else
        {
            tmp=((2*n+1)/3)%1007;
            ans=((ans%1007)*tmp)%1007;
        }
        //cout << tmp << endl;
        cout << ans << endl;
    }
    //cout << wrong << endl;
    return 0;
}
