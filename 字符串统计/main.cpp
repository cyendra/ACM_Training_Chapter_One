#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char str[110];
    int n,len,ans;
    scanf("%d",&n);
    getchar();
    for (int i=0;i<n;i++)
    {
        ans=0;
        scanf("%s",str);
        len=strlen(str);
        for (int j=0;j<len;j++)
        {
            if ((str[j]<='9')and(str[j]>='0'))
            {
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
