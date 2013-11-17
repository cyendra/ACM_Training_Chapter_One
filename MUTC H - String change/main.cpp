#include <iostream>
#include <cstring>

using namespace std;

char s1[66];
char s2[66];

int getnum(char c)
{
    return c-'a';
}
char getchr(int num)
{
    return num+'a';
}
bool sims()
{
    for (int cnt=0;cnt<27;cnt++)
    {
        if (strcmp(s1,s2)==0) return true;
        char t=s1[0];
        s1[0]=getchr((getnum(s1[1])+1)%26);
        s1[1]=getchr((getnum(t)+1)%26);
    }
    return false;
}

int main()
{
    int T,len,ns1,ns2;
    cin>>T;
    for (int cas=1;cas<=T;cas++)
    {
        ns1=ns2=0;
        cin>>s1>>s2;
        len=strlen(s1);
        cout<<"Case #"<<cas<<": ";
        if (len==2)
        {
            if (sims()) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else
        {
            for (int i=0;i<len;i++)
            {
                ns1+=getnum(s1[i]);
                ns2+=getnum(s2[i]);
            }
            if ( ns1%2==ns2%2 ) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}
