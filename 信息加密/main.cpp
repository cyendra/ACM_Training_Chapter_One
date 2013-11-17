#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,l1,l2,p;
    char s1[110],s2[110];
    bool ok;
    while (scanf("%s%s",s1,s2))
    {
        l1=strlen(s1);
        l2=strlen(s2);
        p=0;
        ok=true;
        for (int i=0;i<l2;i++)
        {
            while ((s1[p]!=s2[i])and (p<l1))
            {
                p++;
            }
            if (s1[p]==s2[i])
            {
                p++;
            }
            else
            {
                ok=false;
                break;
            }
        }
        if (ok)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
