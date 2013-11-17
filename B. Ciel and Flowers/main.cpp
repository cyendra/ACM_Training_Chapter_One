#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int r,g,b;
int rr,gg,bb;
int ans;
int ans1;

int main()
{
    while (cin>>rr>>gg>>bb)
    {
        ans=0;
        r=rr;
        g=gg;
        b=bb;
        int tmp=min(r,min(g,b));
        for (int i=max(tmp-6,0); i<=tmp; i++)
        {
            r=rr;
            g=gg;
            b=bb;
            ans1=0;
            r-=i;
            g-=i;
            b-=i;
            ans1+=i;
            ans1+=r/3;
            ans1+=g/3;
            ans1+=b/3;
            ans=max(ans,ans1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
