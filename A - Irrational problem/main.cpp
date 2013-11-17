#include <iostream>

using namespace std;

int p1,p2,p3,p4,a,b;

int f(int x)
{
    return ((((x%p1)%p2)%p3)%p4);
}

int main()
{
    int cnt=0;
    cin>>p1>>p2>>p3>>p4>>a>>b;
    for (int i=a;i<=b;i++)
    {
        if ( f(i)==i )
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
