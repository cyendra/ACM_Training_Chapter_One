#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
int tree[110000];

int lowbit(int i)
{
    return i&(-i);
}

void updata(int i,int d)
{
    while (i<=n)
    {
        tree[i]+=d;
        i+=lowbit(i);
    }
}

long long query(int i)
{
    long long ret=0;
    while (i>0)
    {
        ret+=tree[i];
        i-=lowbit(i);
    }
    return ret;
}

int main()
{
    int m,p,e,a,k;
    while (scanf("%d",&m)!=EOF)
    {
        while (m--)
        {
            scanf("%d",&p);
            if (p==0)
            {
                scanf("%d",&e);
            }
            if (p==1)
            {
                scanf("%d",&e);
            }
            if (p==2)
            {

            }
        }
    }
    return 0;
}
