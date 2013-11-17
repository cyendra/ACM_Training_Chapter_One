#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

void rev(char s[],char ans[],int l,int r)
{
    for (int i=l;i<r;i++)
    {
        ans[i-l]=s[r-i+l-1];
    }
}

int main()
{
    int n,l,r,m;
    bool sp;
    char s[110000];
    char ans[110000];
    while (~scanf("%d",&n))
    {
        if (n==0) break;
        getchar();
        gets(s);
        m=l=r=0;
        sp=false;
        for (int i=0;i<n;i++)
        {
            if (s[i]==' '&&sp) continue;
            if (s[i]==' '&&!sp)
            {
                sp=true;
                ans[m++]=' ';
            }
            if (s[i]>='a'&&s[i]<='z')
            {
                if (sp)
                {
                    l=i;
                    sp=false;
                }
                r=i+1;
                if (s[i+1]==' '||s[i+1]=='\0')
                {
                    rev(s,ans+m,l,r);
                    m+=r-l;
                    l=r;
                }
            }
        }
        ans[m]='\0';
        cout<<ans<<endl;
    }
    return 0;
}
