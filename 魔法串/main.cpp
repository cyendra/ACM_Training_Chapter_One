#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[1111];
char b[1111];
int f[1111][1111];
int la,lb;
int m;
int map[30][30];

int main()
{
    int T;
    char c1,c2;
    cin>>T;
    int cnt=1;
    while (T--)
    {
        memset(f,0,sizeof(f));
        memset(map,0,sizeof(map));
        cin>>(a+1);
        cin>>(b+1);
        la=strlen(a+1);
        lb=strlen(b+1);
        cin>>m;
        for (int i=1;i<=m;i++)
        {
            cin>>c1>>c2;
            map[c1-'a'][c2-'a']=1;
        }
        for (int i=0;i<=lb;i++)
        {
            f[0][i]=1;
        }
        for (int i=1;i<=la;i++)
        {
            for (int j=1;j<=lb;j++)
            {
                if (a[i]==b[j])
                {
                    if (f[i-1][j-1]) f[i][j]=1;
                }
                if (f[i][j-1]) f[i][j]=1;
                for (int k=0;k<26;k++)
                {
                    if (map[b[j]-'a'][k]&&a[i]-'a'==k)
                    {
                        if (f[i-1][j-1]) f[i][j]=1;
                    }
                }
            }
        }
        if (f[la][lb]) cout<<"Case #"<<cnt++<<": happy"<<endl;
        else cout<<"Case #"<<cnt++<<": unhappy"<<endl;
    }
    return 0;
}
