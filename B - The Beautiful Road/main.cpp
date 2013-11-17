#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD=1000000007;
char str[1111];
int numR,R,tmpR;
long long ans,sum;
int main()
{
    int T,len;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        len=strlen(str);
        ans=numR=0;
        for (int i=0;i<len;i++)
            if (str[i]=='R') numR++;
        if (numR==0) ans++;
        bool flag=false;
        for (int i=0;i<len;i++)
        {
            if (str[i]=='R') flag=true;
            if (str[i]=='R'||str[i]=='?')
            {
                if (str[i]=='R'&&numR==1) ans=(ans+1) % MOD;
                if (numR==0) ans=(ans+1) % MOD;
                for (int j=1;i+j<len;j+=2)
                {
                    if (str[i]=='R') R=1;
                    else R=0;
                    for (int k=i+j;k<len;k+=j)
                    {
                        if (str[k]=='R') R++;
                        if (str[k]=='G') break;
                        if (R==numR) ans=(ans+1) % MOD;
                    }
                }
            }
            if (flag) break;
        }
        sum=1;
        for (int i=0;i<len;i++)
            if (str[i]=='?')
                sum=(sum<<1)%MOD;
        ans=(sum-ans+MOD)%MOD;
        printf("%I64d\n",ans);
    }
    return 0;
}



/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MOD=1000000007;
char str[1111];
int numR,R,tmpR;
long long ans;
long long sum;

int main()
{
    int T;
    int len;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        len=strlen(str);
        ans=numR=0;

        for (int i=0;i<len;i++)
        {
            if (str[i]=='R') numR++;
        }
        if (numR==0) ans++;  //GGGGGG
        bool flag=false;
        for (int i=0;i<len;i++)
        {
            if (str[i]=='R') flag=true;
            //if (str[i]=='G') break;
            if (str[i]=='R'||str[i]=='?')
            {
                if (str[i]=='R'&&numR==1) ans=(ans+1) % MOD;//R????
                if (numR==0) ans=(ans+1) % MOD;
                //if (str[i]=='R') tmpR=1;
                //else tmpR=0;
                //if (tmpR==numR) ans=(ans+1)%MOD;
                for (int j=1;i+j<len;j+=2)
                {
                    //R=tmpR;
                    if (str[i]=='R') R=1;
                    else R=0;
                    for (int k=i+j;k<len;k+=j)
                    {
                        if (str[k]=='R') R++;
                        if (str[k]=='G') break;
                        if (R==numR) ans=(ans+1) % MOD;
                    }
                }
            }
            if (flag) break;
        }

        sum=1;
        for (int i=0;i<len;i++)
        {
            if (str[i]=='?')
            {
                sum=sum*2%MOD;
            }
        }
        //cerr<<"ans="<<ans<<endl;
        ans=(sum-ans+MOD)%MOD;
        printf("%I64d\n",ans);

    }
    return 0;
}
*/
