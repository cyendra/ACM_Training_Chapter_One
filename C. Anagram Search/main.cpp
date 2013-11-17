#include <iostream>
#include <cstring>
using namespace std;
char p[111111];
int lenp;
char s[111111];
int lens;
int chr[27];
int match[27];
int gc(char c){
    if (c>='a'&&c<='z') return c-'a';
    return 26;
}
int main()
{
    int ans=0;
    cin>>s>>p;
    memset(match,0,sizeof(match));
    memset(chr,0,sizeof(chr));
    lenp=strlen(p);
    for (int i=0;i<lenp;i++){
        match[gc(p[i])]++;
    }
    lens=strlen(s);
    int l=0;
    int num=0;
    for (int i=0;i<lens;i++){
        chr[gc(s[i])]++;
        num++;
        while (l>=0&&l<=i&&
               ( (s[i]!='?'&&chr[gc(s[i])]>match[gc(s[i])]) || num>lenp )){
            chr[gc(s[l])]--;
            num--;
            l++;
        }
        if (num==lenp) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

