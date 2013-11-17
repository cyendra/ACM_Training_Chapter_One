#include <iostream>
#include <algorithm>
using namespace std;

long long tree[511111]={0};
long long s[511111]={0};
int n,Q;
long long a[511111]={0};

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int x)
{
    while (i<=n)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}

long long query(int i)
{
    int ret=0;
    while (i>0)
    {
        ret+=tree[i];
        i-=lowbit(i);
    }
    return ret;
}

int main()
{
    cin>>n>>Q;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while (Q--)
    {
        int l,r;
        cin>>l>>r;
        updata(l,1);
        updata(r+1,-1);
    }
    for (int i=1;i<=n;i++)
    {
        s[i]=query(i);
    }
    sort(s+1,s+n+1);
    sort(a+1,a+n+1);
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        ans+=s[i]*a[i];
    }
    cout<<ans<<endl;
    return 0;
}
