#include <iostream>

using namespace std;

int main()
{
    long long int n,a;
    string str;
    while (cin >> str)
    {
        if (str=="0")
        {
            break;
        }
        n=0;
        for (int i=0;i<str.length();i++)
        {
            n+=str[i]-'0';
        }
        while ((n/10)!=0)
        {
            a=0;
            while ( n!=0 )
            {
                a+=n%10;
                n=n/10;
            }
            n=a;
        }
        cout << n <<endl;
    }
    return 0;
}
