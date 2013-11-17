#include <iostream>
#include <string>

using namespace std;

int n,m,d;

string str,s;

int tree[1111];

/*
    lowbit
*/
int lowbit(int i)
{
    return i&(-i);
}

/*
    Ò»Î¬Ê÷×´Êý×é
*/
void updata(int i,int x)
{
    while (i<=n)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}

int query(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    int ans=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>str;
        cin>>str;
        cin>>s;
        cin>>str;
        cin>>d;
        if (s=="left")
        {
            updata(d,1);
        }
        else if (s=="right")
        {
            updata(1,1);
            updata(d+1,-1);
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (query(i)==0)
        {
            ans++;
        }
    }
    if (ans==0) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
