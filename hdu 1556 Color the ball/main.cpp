#include <iostream>
#include <cstring>

using namespace std;

int c[111111];
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
    int a,b;
    while (cin>>n)
    {
        if (n==0) break;
        memset(c,0,sizeof(c));
        for (int k=1;k<=n;k++)
        {
            cin>>a>>b;
            updata(a,1);
            updata(b+1,-1);
        }
        for (int i=1;i<n;i++)
        {
            cout<<query(i)<<" ";
        }
        cout<<query(n)<<endl;
    }
    return 0;
}
