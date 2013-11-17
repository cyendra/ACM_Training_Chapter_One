#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    int T;
    int n;
    int mini,len,ans;
    char allstr[256][256];
    char s1[256],s2[256];
    bool ok;
    scanf("%d",&T);
    for (int loop=0;loop<T;loop++)
    {
        len=99999;
        mini=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",allstr[i]);
            if ( strlen( allstr[i] )<len )
            {
                len=strlen( allstr[i] );
                mini=i;
            }
        }
        ans=0;
        for (int i=0;i<len;i++)
        {
            for (int j=1;i+j<=len;j++)
            {
                if (j<=ans)
                {
                    continue;
                }
                strncpy( s1 , allstr[mini]+i , j );
                s1[j]='\0';
                s2[j]='\0';
                for (int tmp=0;tmp<j;tmp++)
                {
                    s2[tmp]=s1[j-tmp-1];
                }
                //strcpy( s2 , s1 );
                //strrev( s2 );

                ok=true;
                for (int k=0; ok==true && k<n;k++)
                {
                    if (k==mini) continue;
                    if ( strstr(allstr[k],s1)==NULL && strstr(allstr[k],s2)==NULL )
                    {
                        ok=false;
                        break;
                    }
                }
                if (ok==false) break;
                if (ok==true && strlen(s1)>ans)
                {
                    ans=strlen(s1);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
