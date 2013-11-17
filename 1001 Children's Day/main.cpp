#include <iostream>
#include <cstring>
using namespace std;

char s[111][111];
int c;

int main()
{
    c=0;
    memset(s,0,sizeof(s));
    for (int sz=3;sz<=10;sz++){
        for (int i=0;i<sz;i++){
            for (int j=0;j<sz;j++){
                s[i][j]=' ';
            }
        }
        for (int i=0;i<sz;i++){
            s[i][0]=c+'a';
            c++;
            if (c>=26) c-=26;
        }
        for (int i=1;i<sz-1;i++){
            s[sz-1-i][i]=c+'a';
            c++;
            if (c>=26) c-=26;
        }
        for (int i=0;i<sz;i++){
            s[i][sz-1]=c+'a';
            c++;
            if (c>=26) c-=26;
        }
        for (int i=0;i<sz;i++){
            s[i][sz]=0;
        }
        for (int i=0;i<sz;i++){
            cout<<s[i]<<endl;
        }
    }
    return 0;
}
