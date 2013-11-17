#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1111];
char a[111],b[111];
int main()
{
    bool dec=false;
    bool dot=false;
    cin>>s;
    if (s[0]=='-') dec=true;
    int len=strlen(s);
    int la=0,lb=0;
    for (int i=dec;i<len;i++){
        if (s[i]=='.'){
            dot=true;
            continue;
        }
        if (!dot) a[la++]=s[i];
        else b[lb++]=s[i];
    }
    a[la]=0;
    b[lb++]='0';
    b[lb++]='0';
    b[lb]=0;
    len=0;
    if (dec) s[len++]='(';
    s[len++]='$';
    int m=la;
    for (int i=0;i<la;i++){
        if (m%3==0&&m!=la) s[len++]=',';
        m--;
        s[len++]=a[i];
    }
    s[len++]='.';
    for (int i=0;i<2;i++) s[len++]=b[i];
    if (dec) s[len++]=')';
    s[len]=0;
    cout<<s<<endl;
    return 0;
}
