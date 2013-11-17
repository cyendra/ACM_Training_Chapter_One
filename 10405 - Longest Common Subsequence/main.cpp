#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s1[1111];
char s2[1111];
int f[1111][1111];

int main()
{
    while (gets(s1+1))
    //while (cin>>(s1+1)>>(s2+1))
    {
        memset(f,0,sizeof(f));
        gets(s2+1);
        int len1=strlen(s1+1);
        int len2=strlen(s2+1);
        for (int i=1;i<=len1;i++)
            for (int j=1;j<=len2;j++)
                f[i][j]=max( f[i-1][j-1]+(s1[i]==s2[j]), max( f[i-1][j], f[i][j-1] ) );
        printf("%d\n",f[len1][len2]);
        //cout<<f[len1][len2]<<endl;
    }
    return 0;
}
