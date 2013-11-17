#include <iostream>

using namespace std;

int t;
int gcd(int a,int b)
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
int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int a,b;
    while ( cin >> a >> b )
    {
        cout << lcm(a,b) << endl;
    }
    return 0;
}
