#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[111];
int a[111];
int len;

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(s,0,sizeof(s));
        scanf("%s",s);
        len=strlen(s);
        for (int i=0;i<len;i++)
        {
            if (s[i]>='a'&&s[i]<='z')
            {
                a[i]=(s[i]-'a')*2+1;
            }
            if (s[i]>='A'&&s[i]<='Z')
            {
                a[i]=(s[i]-'A')*2;
            }
        }
        sort(a,a+len);
        //for (int i=0;i<len;i++) cerr<<a[i]<<" ";
        //cerr<<endl;
        do
        {
            for (int i=0;i<len;i++)
            {
                if (a[i]&1)
                {
                    printf("%c",(a[i]-1)/2+'a');
                }
                else
                {
                    printf("%c",a[i]/2+'A');
                }
            }
            puts("");
        }while (next_permutation(a,a+len));
    }
    return 0;
}
