/*
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,t;
int a[111111]={0};
int s[111111]={0};
int ans;
int c;
int ret;

int main()
{
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    ans=0;
    for (int i=1;i<=n;i++)
    {
        c=s[i]-t;
        for (int j=0;j<i;j++)
        {
            if ( s[j]>=c )
            {
                ret=i-j;
                break;
            }
        }
        if (ans<ret)
        {
            ans=ret;
        }
    }
    cout<<ans<<endl;
    return 0;
}
*/

#include <iostream>
#include <queue>

using namespace std;

int n,t;
int a[111111]={0};
int ans;
int sum;
int ret;

queue<int>que;

int main()
{
    cin>>n>>t;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    while (!que.empty()) que.pop();
    ans=0;
    sum=0;
    for (int i=1;i<=n;i++)
    {
        que.push(a[i]);
        sum+=a[i];
        while ( sum>t )
        {
            ret=que.front();
            sum-=ret;
            que.pop();
        }
        ret=que.size();
        if (ret>ans)
        {
            ans=ret;
        }
    }
    cout<<ans<<endl;
    return 0;
}
