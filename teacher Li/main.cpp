#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n;

char s1[55];
char s2[55];

int cnt;
int main()
{
    cnt=0;
    while (scanf("%d",&n)!=EOF)
    {
        cnt++;
        scanf("%s",s1);
        for (int i=1; i<n+n-1; i++)
        {
            scanf("%s",s2);
            int len=max(strlen(s1),strlen(s2));
            for (int j=0;j<=len;j++)
            {
                s1[j]^=s2[j];
            }
        }
        printf("Scenario #%d\n",cnt);
        printf("%s\n\n",s1);
    }
    return 0;
}
