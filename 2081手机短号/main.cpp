#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    char s[12];
    scanf("%d",&n);
    for (int loop=1;loop<=n;loop++)
    {
        scanf("%s",s);
        printf("6%c%c%c%c%c\n",s[6],s[7],s[8],s[9],s[10]);
    }
    return 0;
}
