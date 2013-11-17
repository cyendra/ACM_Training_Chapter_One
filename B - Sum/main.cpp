#include <iostream>

using namespace std;

int top(int x,int p)
{
    int ret=0;
    int i=1;
    int t;
    while (x>0)
    {
        t=x%10;
        t=t*i;
        ret+=t;
        i*=p;
        x/=10;
    }
    return ret;
}

int bak(int x,int p)
{
    int ret=0;
    while (x>0)
    {
        x/=p;
        ret++;
    }
    return ret;
}

int main()
{
    int a,b,l;
    cin>>a>>b;
    int t;
    l=0;
    t=a;
    while(t>0)
    {
        if (t%10>l) l=t%10;
        t/=10;
    }
    t=b;
    while(t>0)
    {
        if (t%10>l) l=t%10;
        t/=10;
    }
    l+=1;
    int s=top(a,l)+top(b,l);
    int ans=bak(s,l);
    cout<<ans<<endl;
    return 0;
}
