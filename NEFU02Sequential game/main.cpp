#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[111111];

int last;
int zero,one;

int main()
{
    while (~scanf("%s",s))
    {
        int len=strlen(s);
        last=s[0]-'0';
        zero=0;
        one=0;
        if (last==1) one++;
        else zero++;
        for (int i=1;i<len;i++)
        {
            if (s[i]-'0'==last)
            {
                if (s[i]-'0'==1) one++;
                else zero++;
            }
            else
            {
                swap(one,zero);
                last=s[i]-'0';
                if (s[i]-'0'==1) one++;
                else zero++;
            }
        }
        printf("%d %d\n",zero,one);
    }
    return 0;
}
