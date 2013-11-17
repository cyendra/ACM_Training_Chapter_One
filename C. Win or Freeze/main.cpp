#include <iostream>

using namespace std;

const int maxn=5e6;
typedef long long LL;

LL q;
LL ans;
int cnt;
int main()
{
    cnt=0;
    ans=1;
    cin>>q;
    for (LL i=2;i*i<=q;i++){
        while (q%i==0){
            cnt++;
            if (cnt<=2) ans*=i;
            q=q/i;
        }
        if (cnt>2) break;
    }
    if (q>1){
        cnt++;
        if (cnt<=2) ans*=q;
    }
    if (cnt<=1){
        cout<<1<<endl<<0<<endl;
    }
    else if (cnt==2){
        cout<<2<<endl;
    }
    else{
        cout<<1<<endl<<ans<<endl;
    }
    return 0;
}
