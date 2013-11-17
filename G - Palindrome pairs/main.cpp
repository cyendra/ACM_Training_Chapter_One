#include <iostream>
#include <cstring>

using namespace std;

long long f[2222];
char s[2222];
bool q[2222][2222];
long long dp[2222];

int main()
{
    memset(q,0,sizeof(q));
    memset(f,0,sizeof(f));
    memset(dp,0,sizeof(dp));
    cin>>(s+1);
    int len=strlen(s+1);
    for (int i=1;i<=len;i++)
    {
        q[i][i]=true;
        if (s[i]==s[i+1]&&i+1<=len)
        {
            q[i][i+1]=true;
        }
    }

    for (int k=2;k<len;k++)
    {
        for (int i=1;i+k<=len;i++)
        {
            if (s[i]==s[i+k]&&q[i+1][i+k-1])
            {
                q[i][i+k]=true;
            }
        }
    }
    //cout<<len<<endl;
    for (int i=1;i<=len;i++)
    {
        f[i]=f[i-1];
        for (int j=1;j<=i;j++)
        {
            f[i]+=q[j][i];
        }
        //cout<<f[i]<<endl;
    }


    for (int i=1;i<=len;i++)
    {
        int sum=0;
        for (int j=1;j<=i;j++)
        {
            sum+=q[j][i]*f[j-1];
        }
        dp[i]=dp[i-1]+sum;
    }
    cout<<dp[len]<<endl;
    return 0;
}
