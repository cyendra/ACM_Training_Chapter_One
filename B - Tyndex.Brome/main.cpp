#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;

const long long OO=1e15;

long long a[26][111111];
string s,ts;
int n,k;
int lens,lent;
int cnt;
long long ans;
long long mct;

int main()
{
    memset(a,0,sizeof(a));
    cin>>n>>k;
    cin>>s;
    lens=s.length();
    for (int i=0;i<lens;i++)
    {
        int c=s[i]-'a';
        a[c][0]++;
        long long p=a[c][0];
        a[c][p]=i;
    }
    while (n--)
    {
        ans=0;
        cnt=0;
        cin>>ts;
        lent=ts.length();
        for (int i=0;i<lent;i++)
        {
            int c=ts[i]-'a';
            long long p=a[c][0];
            if (p==0)
            {
                ans+=lent;
            }
            else
            {
                mct=OO;
                for (int j=1;j<=p;j++)
                {
                    if (abs(i-a[c][j])<mct)
                    {
                        mct=abs(i-a[c][j]);
                    }
                }
                ans+=mct;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
