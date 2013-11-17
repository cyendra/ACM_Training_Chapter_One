#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    char str[110],tmp[110];
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        gets(str);
        strcpy(tmp,str);
        strrev(tmp);
        if (strcmp(tmp,str)==false)
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
