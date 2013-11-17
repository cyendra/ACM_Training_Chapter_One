#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
    int n,len;
    char s[1024];
    char t[1024];
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {

        gets(s);
        len=strlen(s);
        strcpy(t,s);
        strrev(s);
        if (strcmp(s,t)==false)
        {
            printf("yes");
        }
        else
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
