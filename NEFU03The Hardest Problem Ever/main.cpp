#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char begin[111];
char end[111];
char s[1111];

int main()
{
    while (gets(begin))
    {
        if (strcmp(begin,"ENDOFINPUT")==0) break;
        gets(s);
        gets(end);
        for (int i=0;s[i];i++)
        {
            if (s[i]>='A'&&s[i]<='Z')
            {
                s[i]=((s[i]-'A')+26-5)%26+'A';
            }
        }
        puts(s);
    }
    return 0;
}
