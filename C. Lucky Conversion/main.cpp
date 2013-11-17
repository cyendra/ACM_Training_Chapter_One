#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[111111],b[111111];
int main()
{
    cin>>a>>b;
    int n=strlen(a);
    int res=0;
    int x=0,y=0;
    for (int i=0;i<n;i++){
        if (a[i]!=b[i]){
            if (a[i]=='4') x++;
            else y++;
        }
    }
    res=max(x,y);
    cout<<res<<endl;
    return 0;
}
