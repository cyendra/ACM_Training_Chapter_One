#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int n;
char s[1111];

int main()
{
    cin>>n;
    while (n--)
    {
        scanf("%s",s);
        int len=strlen(s);
        if (len<=10)
        {
            printf("%s\n",s);
        }
        else
        {
            printf("%c%d%c\n",s[0],len-2,s[len-1]);
        }
    }
    return 0;
}
