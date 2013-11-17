#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
const int maxn=111;
const int mod=1000000007;
char s[maxn][maxn];
int n,m;
LL ans;
int a[256];
int e;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>(s[i]+1);
    }
    ans=1;
    for (int i=1;i<=m;i++){
        memset(a,0,sizeof(a));
        e=0;
        for (int j=1;j<=n;j++){
            if (a[s[j][i]-'A']==0){
                e++;
                a[s[j][i]-'A']=1;
            }
        }
        ans=ans*e%mod;
        //cerr<<"---"<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
