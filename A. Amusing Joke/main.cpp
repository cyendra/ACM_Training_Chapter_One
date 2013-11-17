#include <iostream>
#include <cstring>
using namespace std;

char a[1111];
int ch[26]={0};

int main()
{
    cin>>a;
    for (int i=0;a[i];i++){
        ch[a[i]-'A']++;
    }
    cin>>a;
    for (int i=0;a[i];i++){
        ch[a[i]-'A']++;
    }
    cin>>a;
    for (int i=0;a[i];i++){
        ch[a[i]-'A']--;
    }
    bool flag=true;
    for (int i=0;i<26;i++){
        if (ch[i]!=0){
            cout<<"NO"<<endl;
            flag=false;
            break;
        }
    }
    if (flag) cout<<"YES"<<endl;
    return 0;
}
