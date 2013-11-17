#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string s;
string add="nanodesu";
int T;
int main()
{
    cin>>T;
    for (int cas=1;cas<=T;cas++){
        cin>>s;
        if (s.length()>3&&s.substr(s.length()-4,4)=="desu"){
            string ans=s.substr(0,s.length()-4)+add;
            cout<<"Case #"<<cas<<": "<<ans<<endl;
        }
        else{
            string ans=s+add;
            cout<<"Case #"<<cas<<": "<<ans<<endl;
        }
    }
    return 0;
}
