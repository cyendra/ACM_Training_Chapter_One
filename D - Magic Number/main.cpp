#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1111;

char words[2222][22];
int f[22][22];
char s[22];

int main()
{
    int T;
    int n,m;
    int thr;
    int len1,len2;
    int ans;
    scanf("%d",&T);
    for (int lp=1;lp<=T;lp++)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",words[i]+1);
        }
        printf("Case #%d:\n",lp);
        while (m--)
        {
            ans=0;
            scanf("%s%d",s+1,&thr);
            len1=strlen(s+1);
            for (int p=1;p<=n;p++)
            {
                len2=strlen(words[p]+1);
                for (int i=0;i<=len1;i++) f[i][0]=i;
                for (int i=0;i<=len2;i++) f[0][i]=i;
                for (int i=1;i<=len1;i++)
                {
                    for (int j=1;j<=len2;j++)
                    {
                        f[i][j]=min(f[i-1][j]+1,f[i][j-1]+1);
                        if (s[i]==words[p][j]) f[i][j]=min(f[i][j],f[i-1][j-1]);
                        else f[i][j]=min(f[i][j],f[i-1][j-1]+1);
                    }
                }
                if (f[len1][len2]<=thr) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
