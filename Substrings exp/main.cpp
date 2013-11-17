#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
char s[222][222];
char tmp[222];
char pmt[222];
int ans;
bool ok;
int main()
{
    int T,len,p;
    scanf("%d",&T);
    while (T--)
    {
        len=p=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s[i]);
            if (strlen(s[i])>len)
            {
                len=strlen(s[i]);
                p=i;
            }
        }
        for (int L=len;L>=0;L--)
        {
            for (int i=0;i+L<=len;i++)
            {
                for (int k=0;k<L;k++)
                {
                    tmp[k]=s[p][i+k];
                }
                tmp[L]='\0';
                int ll=strlen(tmp);
                for (int g=0;g<ll;g++)
                {
                    pmt[g]=tmp[ll-g-1];
                }
                pmt[ll]='\0';
                ok=true;
                for (int j=1;j<=n;j++)
                {
                    if (strstr(s[j],tmp)==NULL&&strstr(s[j],pmt)==NULL)
                    {
                        ok=false;
                        break;
                    }
                }
                if (ok)
                {
                    ans=L;
                    break;
                }
            }
            if (ok) break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
