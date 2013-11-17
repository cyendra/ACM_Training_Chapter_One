#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n;
    char str[1000];
    char c[10];
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        scanf("%s%s",str,c);
        printf("Case #%d: ",i+1);
        if (strstr(str,c)==NULL)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    return 0;
}
