#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef long long LL;
LL n,m;

bool onField(LL x,LL y){
    if (x>=1&&x<=n&&y>=1&&y<=m) return true;
    return false;
}

LL fun(LL x,LL y,LL dx,LL dy){
    LL res=0;
    LL l=0,r=(1LL<<32);
    while (l<=r){
        LL mid=l+(r-l)/2;
        if (onField(x+dx*mid,y+dy*mid)){
            res=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return res;
}

int main()
{
    LL x,y,T,ans;
    ans=0;
    cin>>n>>m;
    cin>>x>>y;
    cin>>T;
    while (T--){
        LL dx,dy;
        cin>>dx>>dy;
        LL res=fun(x,y,dx,dy);
        ans+=res;
        x+=dx*res;
        y+=dy*res;
    }
    cout<<ans<<endl;
    return 0;
}
