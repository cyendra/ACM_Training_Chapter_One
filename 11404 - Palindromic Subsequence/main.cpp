#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[1111];
char b[1111];
int f[1111][1111];
char ans[1111];
int cnt;

struct ANP
{
    int x;
    int y;
    char c;
    string s;
} p[1111][1111];

int main()
{
    while (cin>>(a+1))
    {
        memset(f,0,sizeof(f));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        memset(p,0,sizeof(p));
        cnt=0;
        int len=strlen(a+1);
        for (int i=1; i<=len; i++)
        {
            b[len-i+1]=a[i];
        }
        b[len+1]='\0';
        for (int i=1; i<=len; i++)
        {
            for (int j=1; j<=len; j++)
            {
                if (a[i]==b[j])
                {
                    f[i][j]=f[i-1][j-1]+1;
                    p[i][j].x=i-1;
                    p[i][j].y=j-1;
                    p[i][j].c=a[i];
                    p[i][j].s=p[i-1][j-1]+p[i][j].c;
                }
                else
                {
                    if (f[i-1][j]>f[i][j-1])
                    {
                        f[i][j]=f[i-1][j];
                        p[i][j]=p[i-1][j];
                    }
                    else if (f[i][j-1]>f[i-1][j])
                    {
                        f[i][j]=f[i][j-1];
                        p[i][j]=p[i][j-1];
                    }
                    else
                    {
                        f[i][j]=f[i-1][j];
                        if (p[i-1][j].s<=p[i][j-1].s)
                        {
                            p[i][j]=p[i-1][j];
                        }
                        else
                        {
                            p[i][j]=p[i][j-1];
                        }
                    }
                }
            }
        }
        int x=len;
        int y=len;
        while (x!=0&&y!=0)
        {
            cout<<p[x][y].c;
            int tx=p[x][y].x;
            int ty=p[x][y].y;
            x=tx;
            y=ty;
        }
        cout<<endl;
    }
    return 0;
}

//----------------
/*
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<list>
#define pi acos(-1.0)
#define inf (1<<29)
#define Clear(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define ppb pop_back
#define sz(a) ((int)a.size())
#define eps 1e-9

#define rep(i,init,n) for(int i=init;i<n;i++)
#define rem(i,init,n) for(int i=init;i>n;i--)

#define sqr(x) ((x)*(x))

#define si(a) scanf("%d",&a)
#define sd(a) scanf("%lf",&a)
#define sc(a) scanf("%c",&a)
#define ss(a) scanf("%s",a)

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

char s1[1111],s2[1111],s[1111];
int dp[1111][1111];

string order[1005][1005];
void reset()
{
    Clear(s1);
    Clear(s);
    Clear(s2);
    Clear(dp);

    for(int i=0;i<=103;i++)
        for(int j=0;j<=103;j++)
            order[i][j].clear();
}
void f(char s1[],int l1,char s2[],int l2)
{
    for(int i=0;i<l1;i++)
    {
        for(int j=0;j<l2;j++)
        {
            if(s1[i]==s2[j])
            {
                dp[i+1][j+1]=dp[i][j]+1;
                order[i+1][j+1]=order[i][j]+s1[i];
  //              cout<<order[i+1][j+1]<<endl;
            }
            else
            {
                if(dp[i][j+1]>dp[i+1][j])
                {
                    dp[i+1][j+1]=dp[i][j+1];
                    order[i+1][j+1]=order[i][j+1];
                }
                else if(dp[i+1][j]>dp[i][j+1])
                {
                    dp[i+1][j+1]=dp[i+1][j];
                    order[i+1][j+1]=order[i+1][j];
                }
                else
                {
                    dp[i+1][j+1]=dp[i][j+1];
                    if(order[i][j+1]<=order[i+1][j])
                    {
                        order[i+1][j+1]=order[i][j+1];
                    }
                    else
                    {
                        order[i+1][j+1]=order[i+1][j];
                    }
                }
//                cout<<order[i+1][j+1]<<endl;
            }
        }
    }
    int l=order[l1][l2].size();
    for(int i=0;i<l/2;i++)
    {
        if(order[l1][l2][i]!=order[l1][l2][l-i-1])
        {
            order[l1][l2][l-i-1]=order[l1][l2][i];
        }
    }
    cout<<order[l1][l2]<<endl;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int CASE=0,i=0,j=0,n=0,ii=0,jj=0,T;
    while(scanf("%s",s1)!=EOF)
    {
        strcpy(s2,s1);
        reverse(s2,s2+strlen(s2));
        //printf("Case %d: ",++CASE);

        f(s1,strlen(s1),s2,strlen(s2));

        reset();
        i=0,j=0,n=0,ii=0,jj=0;
    }
}
*/
