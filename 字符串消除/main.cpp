#include <iostream>
#include <cstring>
using namespace std;

int minLength(const char *s){
    int a[3]={0};
    int len=strlen(s);
    for (int i=0;i<len;i++){
        a[s[i]-'a']++;
    }
    if ( max(a[0],max(a[1],a[2]))==len ) return len;
    int odd=0,even=0;
    for (int i=0;i<3;i++){
        if (a[i]&1) odd++;
        else even++;
    }
    if (odd==3||even==3) return 2;
    else return 1;
}
int main()
{
    char str[222];
    cin>>str;
    cout<<minLength(str)<<endl;
    return 0;
}
