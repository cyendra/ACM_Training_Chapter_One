/*
ID: g1483331
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char a[111],b[111];

int hentai(char *s)
{
    int len=strlen(s);
    int ret=1;
    for (int i=0;i<len;i++)
    {
        ret*=s[i]-'A'+1;
        ret%=47;
    }
    return ret;
}

int main()
{
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    scanf("%s",a);
    scanf("%s",b);
    if (hentai(a)==hentai(b))
    {
        printf("GO\n");
    }
    else
    {
        printf("STAY\n");
    }

    return 0;
}
