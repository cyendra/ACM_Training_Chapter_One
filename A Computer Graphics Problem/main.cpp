#include <iostream>

using namespace std;

char s[3][21]={ {"*------------*\0"},{"|............|\0"},{"|------------|\0"} };

int main()
{
    int T,n;
    cin>>T;
    for (int cas=1;cas<=T;cas++){
        cin>>n;
        cout<<"Case #"<<cas<<":"<<endl;
        cout<<s[0]<<endl;
        for (int i=100;i>=10;i-=10){
            if (n>=i) cout<<s[2]<<endl;
            else cout<<s[1]<<endl;
        }
        cout<<s[0]<<endl;
    }
    return 0;
}
