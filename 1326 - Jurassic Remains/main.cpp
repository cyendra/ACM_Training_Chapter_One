#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

const int maxn=24;
map<int,int>mp;

int bitcount(int x)
{
    return x==0?0:(bitcount(x>>1)+(x&1));
}

int main()
{
    int n,a[maxn];
    char s[1111];
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        getchar();
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            a[i]=0;
            for (int j=0;s[j];j++)
            {
                a[i]^=(1<<(s[j]-'A'));
            }
        }
        mp.clear();
        int n1=n/2,n2=n-n1;
        for (int i=0;i<(1<<n1);i++)
        {
            int x=0;
            for (int j=0;j<n1;j++)
            {
                if (i&(1<<j)) x^=a[j];
            }
            if (!mp.count(x)||bitcount(mp[x])<bitcount(i))
                mp[x]=i;
        }
        int ans=0;
        for (int i=0;i<(1<<n2);i++)
        {
            int x=0;
            for (int j=0;j<n2;j++)
            {
                if (i&(1<<j)) x^=a[n1+j];
            }
            if (mp.count(x)&&bitcount(ans)<bitcount(mp[x])+bitcount(i))
                ans=(i<<n1)^mp[x];
        }
        printf("%d\n",bitcount(ans));
        for (int i=0;i<n;i++)
        {
            if (ans&(1<<i))
            {
                printf("%d ",i+1);
            }
        }
        printf("\n");
    }
    return 0;
}
