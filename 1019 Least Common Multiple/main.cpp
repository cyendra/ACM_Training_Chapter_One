#include <iostream>

using namespace std;
long long int t;
long long int gcd(long long int a,long long int b)
{
    if (b>a)
    {
        t=a;
        a=b;
        b=t;
    }
    if (b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}

long long int lcm(long long int a,long long int b)
{
    return ( a/gcd(a,b)*b );
}

int main()
{
    long long int p,n,a,last;
    cin >> p;
    for (int loop=0;loop<p;loop++)
    {
        cin >> n;
        last=1;
        for (int i=0;i<n;i++)
        {
            cin >> a;
            last=lcm(last,a);
        }
        cout << last << endl;
    }
    return 0;
}
