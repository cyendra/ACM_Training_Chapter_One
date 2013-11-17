#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

const int maxn=111111;
const int INF=1e9+7;
int f[maxn];
int a[maxn];
int n;
stack<int>stk;

int main()
{
    int ans;
    while (cin>>n)
    {
        ans=0;
        while (!stk.empty()) stk.pop();
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++) cin>>a[i];
        f[0]=INF;
        stk.push(0);
        for (int i=1;i<=n;i++)
        {
            f[i]=1;
            while (!stk.empty()&&a[i]>a[stk.top()])
            {
                f[i]=max(f[i],f[stk.top()]+1);
                stk.pop();
            }
            stk.push(i);
            if (f[i]<INF) ans=max(ans,f[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
