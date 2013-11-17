#include <iostream>

using namespace std;

typedef long long int LL;

double n;

int main()
{
    while (cin>>n)
    {
        while(n>18) n/=18;
        if (n<=9)
        {
            cout<<"Stan wins."<<endl;
        }
        else
        {
            cout<<"Ollie wins."<<endl;
        }
    }
    return 0;
}
