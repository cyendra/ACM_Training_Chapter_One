#include <iostream>
#include <string>
using namespace std;

int main()
{
    int p;
    string s,t;
    cin>>s;
    cin>>t;
    p=0;
    for (int i=0;i<t.length();i++)
    {
        if ( s[p]==t[i] ) p++;
    }
    p++;
    cout<<p<<endl;
    return 0;
}

