#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
char str[1111];
int T;
int n;
//string s;

int ans;
int main()
{
    freopen("C-small-2-attempt0.in","r",stdin);
    freopen("C-small-2-attempt0.out","w",stdout);
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++){
        string mx;
        scanf("%d",&n);
        ans=0;
        getchar();
        for (int i=1;i<=n;i++){
            gets(str);
            string s(str);
            if (i==1) mx=s;
            if (s<mx){
                ans++;
            }
            else if (s>mx){
                mx=s;
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
