#include <iostream>
#include <cstring>

using namespace std;

struct node{
    int cnt;
    long long sum;
};

node c[111111];
int n;

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int v,int cnt)
{
    while (i<=n)
    {
        c[i].sum+=v;
        c[i].cnt+=cnt;
        i+=lowbit(i);
    }
}

int query_cnt(int i)
{
    int sum=0;
    while (i>0)
    {
        sum+=c[i].cnt;
        i-=lowbit(i);
    }
    return sum;
}

long long query_sum(int i)
{
    long long sum=0;
    while (i>0)
    {
        sum+=c[i].sum;
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    int tmp;
    long long k1,k2;
    while (cin>>n)
    {
        long long ans=0;
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;i++)
        {
            cin>>tmp;
            updata(tmp,tmp,1);
            k1=i-query_cnt(tmp);
            if (k1!=0)
            {
                k2=query_sum(n)-query_sum(tmp);
                ans+=k1*tmp+k2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
