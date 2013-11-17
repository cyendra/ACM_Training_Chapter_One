#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[111];
int b[111];
char sa[111];
char sb[111];
int lena,lenb;

int main()
{
    while (cin>>sa>>sb)
    {
        if (strcmp(sa,sb)==0&&strcmp(sa,"0")==0) break;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        lena=strlen(sa);
        lenb=strlen(sb);
        for (int i=0;i<lena;i++) a[i]=sa[lena-i-1]-'0';
        for (int i=0;i<lenb;i++) b[i]=sb[lenb-i-1]-'0';
        int ans=0;
        for (int i=0;i<max(lena,lenb);i++)
        {
            a[i]+=b[i];
            if (a[i]>=10)
            {
                a[i+1]+=1;
                a[i]-=10;
                ans++;
            }
        }
        if (ans==1) cout<<ans<<" carry operation."<<endl;
        else if (ans>1) cout<<ans<<" carry operations."<<endl;
        else cout<<"No carry operation."<<endl;
    }
    return 0;
}
