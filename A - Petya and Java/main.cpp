#include <iostream>
#include <string>

using namespace std;

string sbyte1="-128";
string sbyte2="127";
string sshort1="-32768";
string sshort2="32767";
string sint1="-2147483648";
string sint2="2147483647";
string slong1="-9223372036854775808";
string slong2="9223372036854775807";
string str;

int main()
{
    cin>>str;
    int len=str.length();
    if (len<sbyte2.length()||(len==sbyte2.length()&&str<=sbyte2))
    {
        cout<<"byte";
    }
    else if (len<sshort2.length()||(len==sshort2.length()&&str<=sshort2))
    {
        cout<<"short";
    }
    else if (len<sint2.length()||(len==sint2.length()&&str<=sint2))
    {
        cout<<"int";
    }
    else if (len<slong2.length()||(len==slong2.length()&&str<=slong2))
    {
        cout<<"long";
    }
    else
    {
        cout<<"BigInteger";
    }
    cout<<endl;

    return 0;
}

