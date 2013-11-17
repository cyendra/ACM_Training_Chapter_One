#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct LSH{
    long long v;
    int index;
    int ls;
}lsh[500000];

long long tree[500000];
const int maxn=500000;
int m,n;

bool cmp(LSH a,LSH b)
{
    return a.v<b.v;
}

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
    long long sum=0;
    while (i>0)
    {
        sum+=tree[i];
        i-=lowbit(i);
    }
    return sum;
}

int main()
{
    long long ret;
    while (cin>>n)
    {
        if (n==0) break;
        memset(lsh,0,sizeof(lsh));
        memset(tree,0,sizeof(tree));
        for (int i=1;i<=n;i++)
        {
            cin>>lsh[i].v;
            lsh[i].index=i;
        }
        sort(lsh+1,lsh+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            lsh[lsh[i].index].ls=i;
        }
        ret=0;
        for (int i=1;i<=n;i++)
        {
            updata(lsh[i].ls,1);
            ret+=i-query(lsh[i].ls);
        }
        cout<<ret<<endl;
    }
    return 0;
}
