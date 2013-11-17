#include <iostream>

using namespace std;

int main()
{
    int n;
    char s[111];
    cin>>n>>s;
    bool ok=true;
    for (int i=0;i<n;i++){
        if (s[i]!='4'&&s[i]!='7'){
            ok=false;
            break;
        }
    }
    if (!ok) cout<<"NO"<<endl;
    else{
        int a=0,b=0;
        for (int i=0;i<n;i++){
            if (i<n/2) a+=s[i]-'0';
            else b+=s[i]-'0';
        }
        if (a==b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
