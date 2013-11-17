#include <iostream>
#include <cstring>

using namespace std;

int cost[2002];

int n,m;
char s[2222];
char chr;
int add,del;

int f[2222][2222];

int main()
{
    cin>>n>>m;
    memset(f,0,sizeof(f));
    memset(cost,0,sizeof(cost));
    cin>>(s+1);
    for (int i=0; i<n; i++)
    {
        cin>>chr>>add>>del;
        cost[chr-'a']=min(add,del);
    }

    for (int i=m-1; i>=1; i--)
    {
        for (int j=i+1; j<=m; j++)
        {
            if ( s[i]==s[j] ) f[i][j]=f[i+1][j-1];
            else f[i][j]=min( f[i+1][j]+cost[s[i]-'a'] , f[i][j-1]+cost[s[j]-'a'] );
        }
    }
    cout<<f[1][m]<<endl;
    return 0;
}

/*
#include<iostream>
using namespace std;
#define min(x,y) (x)<(y)? (x):(y)
int dp[2002][2002],cost[2002];
char s[2002],c;
int main()
{
    int i,j,m,n;
    int a,b;
    cin>>m>>n>>s+1;
    for(i=1; i<=m; i++)
    {
        cin>>c>>a>>b;
        cost[c-'a']=min(a,b);
    }
    for(i=n-1; i>=1; i--)
        for(j=i+1; j<=n; j++)
        {
            if(s[i]==s[j])
                dp[i][j]=dp[i+1][j-1];
            else
            {
                a=dp[i+1][j]+cost[s[i]-'a'];
                b=dp[i][j-1]+cost[s[j]-'a'];
                dp[i][j]=min(a,b);
            }
        }
    cout<<dp[1][n]<<endl;
    return 0;
}
*/
