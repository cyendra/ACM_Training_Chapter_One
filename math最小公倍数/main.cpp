#include <iostream>

using namespace std;

typedef long long int LL;

LL gcd(LL a,LL b)
{
    if (a%b==0)
    {
        return b;
    }
    else return gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    LL a,b,c;
    LL ans;
    while (cin>>a>>b>>c)
    {
        ans=lcm(lcm(a,b),c);
        cout<<ans<<endl;
    }
    return 0;
}
