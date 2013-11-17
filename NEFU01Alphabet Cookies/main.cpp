#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;
char s[111];
char mk[111];
int a[30];

int main()
{
    while (~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        scanf("%s",mk);
        for (int i=0;i<n;i++)
        {
            a[ s[i]-'A' ]++;
        }
        bool ok=true;
        for (int i=0;mk[i];i++)
        {
            if ( a[ mk[i]-'A' ]>0 )
            {
                a[ mk[i]-'A' ]--;
            }
            else
            {
                ok=false;
                break;
            }
        }
        if (ok)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
