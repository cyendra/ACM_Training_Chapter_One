#include <iostream>
#include <string>

using namespace std;

string s;

int main()
{
    cin>>s;
    if ( s[0]>='a'&&s[0]<='z' )
    {
        s[0]+='A'-'a';
    }
    cout<<s<<endl;
    return 0;
}
