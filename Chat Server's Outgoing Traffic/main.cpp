#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[256];
    char *p;
    int ans;
    int num;
    num=0;
    ans=0;
    while (gets(str)!=NULL)
    {
        if (str[0]=='+')
        {
            num++;
            continue;
        }
        if (str[0]=='-')
        {
            num--;
            continue;
        }
        p=strchr(str,':');
        p++;
        ans+=strlen(p)*num;
        //printf("%d %d\n",num,ans);
    }
    printf("%d\n",ans);
    return 0;
}
