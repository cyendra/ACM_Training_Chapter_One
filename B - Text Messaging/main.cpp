#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

char s[11111];
int a[11111]={0};
int c[11111]={0};
int space[11111]={0};
int ta[11111]={0};

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    gets(s+1);
    int len=strlen(s+1);
    int p=0;
    int sps=0;
    bool word=true;
    for (int i=1;i<=len;i++)
    {
        if (s[i]=='.'||s[i]=='?'||s[i]=='!')
        {
            p++;
            ta[p]=i;
            space[p]=sps;
            sps=0;
            word=false;
        }
        if (s[i]==' '&&word==false)
        {
            sps++;
        }
        if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        {
            word=true;
        }
    }
    for (int i=1;i<=p;i++) a[i]=ta[i]-ta[i-1];
    int l=1;
    bool flag=true;
    for (int i=1;i<=p;i++)
    {
        if (c[l]+a[i]<=n)
        {
            c[l]+=a[i];
        }
        else
        {
            l++;
            c[l]=a[i]-space[i];
            if (c[l]>n) {flag=false;break;}
        }
    }
    /*
    for (int i=1;i<=p;i++) cerr<<ta[i]<<" ";cerr<<endl;
    for (int i=1;i<=p;i++) cerr<<a[i]<<" ";cerr<<endl;
    for (int i=1;i<=p;i++) cerr<<space[i]<<" ";cerr<<endl;
    for (int i=1;i<=l;i++) cerr<<c[i]<<" ";cerr<<endl;
    */
    if (flag) cout<<l<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}

