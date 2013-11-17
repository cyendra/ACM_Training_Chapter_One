#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;

LL n,a,b,x,y,s,t;

LL gcd(LL a,LL b)
{
    return b? gcd(b,a%b):a;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>a>>b;
        if(a<b) swap(a,b);
        x=a;y=b;
        LL m=a*b/gcd(a,b);
        LL tmp=0,sum=0;
        while(tmp<m)
        {
            LL r=tmp%x-tmp%y;
            if(r<0) r=-r;
            s=x-tmp%x;
            t=y-tmp%y;
            if(s<t)
            {
                sum+=r*s;
                tmp+=s;
            }
            else
            {
                sum+=r*t;
                tmp+=t;
            }
        }
        LL ans=0;
        ans+=(n/m*sum);
        n%=m;
        tmp=0,sum=0;
        while(tmp<n)
        {
            LL r=tmp%x-tmp%y;
            if(r<0)r=-r;
            s=x-tmp%x;
            t=y-tmp%y;
            if(s<t&&(tmp+s)<=n)
            {
                sum+=r*s;
                tmp+=s;
            }
            else if(t<=s&&(tmp+t)<=n)
            {
                sum+=r*t;
                tmp+=t;
            }
            else break;
        }
        if(tmp<n)
        {
            LL r=tmp%x-tmp%y;
            if(r<0) r=-r;
            sum+=(n-tmp)*r;
        }
        ans+=sum;
        cout<<ans<<endl;
    }
    return 0;
}
