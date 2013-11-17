#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

int fg[1000001];
int prim[1000001]={0};
int np;
const int maxn=1000000;

map<int,int>mp;

int main()
{
    int n,ans;
    np=0;
    for(int i = 2; i < maxn; i ++)
    {
        if (!fg[i])
        {
            prim[np] = i;
            mp[i]=np;
            np++;
        }
        for(int j = 0; j < np && i*prim[j] < maxn; j ++)
        {
            fg[i*prim[j]] = 1;
            if (i % prim[j] == 0)break;
        }
    }
    while (cin>>n)
    {
        ans=0;
        for (int i=n;i>=2;i--)
        {
            if (n%i==0 && !fg[i])
            {
                //cout<<"i= "<<i<<endl;
                ans=mp[i]+1;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
