#include <iostream>
#include <cstring>

using namespace std;

int c[1111];
int n;

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int x)
{
    while (i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
}

int query(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=c[i];
        i-=lowbit(i);
    }
    return sum;
}



int main()
{
    int t;
    while (cin>>n)
    {
        if (n==0) break;
        memset(c,0,sizeof(c));
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            cin>>t;
            updata(t,1);
            ans+=i-query(t);
        }
        cout<<ans<<endl;
    }
    return 0;
}
