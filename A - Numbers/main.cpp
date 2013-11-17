#include <iostream>

using namespace std;

int gcd(int a,int b)
{
    int t;
    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while ( b!=0 )
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
}

int main()
{
    int n,tmp;
    int sum=0;
    int fz,fm;
    cin >> n;
    for (int i=2;i<n;i++)
    {
        tmp=n;
        for (;tmp;tmp/=i)
        {
            sum=sum+tmp%i;
        }
    }
    fm=n-2;
    fz=sum;
    tmp=gcd(fz,fm);
    fz/=tmp;
    fm/=tmp;
    cout << fz << "/" << fm << endl;
    return 0;
}
