#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s1[111];
char s2[111];
int n;
int f[111][111];

int main()
{
    int cnt=1;
    while (gets(s1+1))
    {
        if (s1[1]=='#') break;
        memset(f,0,sizeof(f));
        gets(s2+1);
        int len1=strlen(s1+1);
        int len2=strlen(s2+1);
        for (int i=1;i<=len1;i++)
        {
            for (int j=1;j<=len2;j++)
            {
                if (s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
                f[i][j]=max(f[i][j], max(f[i-1][j], f[i][j-1]));
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",cnt++,f[len1][len2]);
    }
    return 0;
}
