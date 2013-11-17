#include <iostream>
//#include <map>
#include <cstring>
#include <string>

using namespace std;

int m,n;
string str;
//map<string,int>mp;
string mp[111];
bool f[111111];
int w[11][111];
int s[1111];
int ans;

int getid(string s)
{
    for (int i=1;i<=m;i++)
    {
        if ( mp[i]==s ) return i;
    }
    return 0;
}

int main()
{
    int t,d,c,k;
    while (cin>>m>>n)
    {
        if (m==0&&n==0) break;
        //mp.clear();
        for (int i=1;i<=m;i++)
        {
            cin>>str;
            mp[i]=str;
            //mp[str]=i;
        }

        memset(w,0,sizeof(w));
        memset(s,0,sizeof(s));
        for (int i=1;i<=n;i++)
        {
            cin>>t>>str;
            //c=mp[str];
            c=getid(str);
            w[c][0]++;
            d=w[c][0];
            w[c][d]=t;
            s[c]+=t;
        }
        ans=0;
        for (int lp=1;lp<=m;lp++)
        {
            for (int i=0;i<=s[lp]/2;i++) f[i]=0;
            f[0]=1;
            for (int i=1;i<=w[lp][0];i++)
            {
                for (int j=s[lp]/2-w[lp][i];j>=0;j--)
                {
                   if (f[j]) f[j+w[lp][i]]=1;
                }
            }
            for (k=s[lp]/2;k>=0;k--)
            {
                if (f[k]) break;
            }
            ans+=(s[lp]-k);
        }
        cout<<ans<<endl;
    }
    return 0;
}
