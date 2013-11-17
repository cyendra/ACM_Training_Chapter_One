#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>

using namespace std;

int main()
{
    bool ans;
    char str[100];
    int n,p;
    scanf("%d%*c",&n);
    while (n--)
    {

        gets(str);
        if ( !isalpha(str[0]) && (str[0]!='_') )
        {
            puts("no");
            continue;
        }
        ans=true;
        for (p=1;str[p];p++)
        {
            //if ((str[p]==' ')){ans=false;break;}
            if ( !isalnum(str[p]) && str[p] != '_'  )
            {
                ans=false;
                break;
            }
        }
        if (ans==true)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }
    }
    return 0;
}
