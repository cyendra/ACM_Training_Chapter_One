#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string s;

int main()
{
    long long ans=0;
    while (cin>>s)
    {
        if (s.find("manure")!=string::npos)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
