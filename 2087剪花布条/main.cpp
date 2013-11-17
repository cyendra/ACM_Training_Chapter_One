#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    bool ok;
    char s[1000],a[1000];
    int sum;
    while (scanf("%s",s))
    {
        if ((s[0]=='#')&&(s[1]=='\0'))
        {
            break;
        }
        scanf("%s",a);
        sum=0;
        for (int i=0;i<strlen(s);i++)
        {
            ok=true;
            for (int j=0;j<strlen(a);j++)
            {
                if (s[i+j]!=a[j])
                {
                    ok=false;
                }
            }
            if (ok==true)
            {
                sum++;
                for (int j=0;j<strlen(a);j++)
                {
                    s[i+j]=' ';
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
