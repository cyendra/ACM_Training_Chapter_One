
#include <stdio.h>
#include <string.h>
int s[512];
long long int ans;
char str[111111];

int main()
{

    gets(str);
    for (int i=0;str[i];i++)
    {
        s[str[i]]++;
    }

    ans=0;
    for (int i=48;i<=122;i++)
    {
        ans+=1LL*(long long)(s[i])*(long long)(s[i]);
    }
    //cout<<ans<<endl;
    printf("%I64d\n",ans);
    return 0;
}

/*
#include <cstdio>
int c[333]; char s[111111]; long long r;
int main() {
    gets(s); for (int i=r=0;s[i];i++) c[s[i]]++; for (int i = 1;i < 200;i++) r+=1LL*c[i]*c[i];
    printf("%I64d\n", r);
}
*/
