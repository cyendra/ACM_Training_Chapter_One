#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[1111];

int main()
{
    while (~scanf("%s",s))
    {
        int a=0;
        int b=0;
        int l=strlen(s);
        int m=l/2;
        if (strcmp(s,"0")==0) break;
        if (strlen(s)==1)
        {
            printf("Y\n");
            continue;
        }
        for (int i=0;i<m;i++)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                a+=s[i]-'0';
            }
            else if (s[i]>='A'&&s[i]<='F')
            {
                a+=s[i]-'A'+10;
            }
        }
        for (int i=l-1,t=0;t<m;t++,i--)
        {
            if (s[i]>='0'&&s[i]<='9')
            {
                b+=s[i]-'0';
            }
            else if (s[i]>='A'&&s[i]<='F')
            {
                b+=s[i]-'A'+10;
            }
        }
        if (a==b) printf("Y\n");
        else printf("N\n");
    }
    return 0;
}
