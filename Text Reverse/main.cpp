#include <cstring>
#include <cstdio>

using namespace std;

int n;
char s[11111];
char * r;
char c;

int main()
{
    scanf("%d",&n);
    getchar();
    while ( scanf("%s",s)!=EOF )
    {
        r=strrev(s);
        printf("%s",r);
        while (c=getchar())
        {
            if (c==' '||c=='\n'||c=='\r')
            {
                printf("%c",c);
            }
            else break;
        }
        ungetc(c,stdin);
    }
    return 0;
}
