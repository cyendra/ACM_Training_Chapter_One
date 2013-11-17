#include <iostream>
#include <string>

using namespace std;

const int OO=1e9;

int n,m;
int minlen;
int len;
string words[33];
string s;
int wdv[33];

int FG(const string &s,int p,int d)
{
    int ret=0;
    for (int i=p;i<p+d;i++)
    {
        ret+=s[i]-'A';
    }
    ret%=minlen+44;
    return ret;
}

int main()
{
    int cnt=0;
    while (cin>>n>>m)
    {
        cnt++;
        minlen=OO;
        for (int i=0;i<n;i++)
        {
            cin>>words[i];
            if (words[i].length()<minlen)
            {
                minlen=words[i].length();
            }
        }
        cin>>s;
        len=s.length();

        for (int i=0;i<n;i++)
        {
            wdv[i]=FG( words[i], words[i].length()-m ,m );
        }

        int ans=0;
        bool flag=false;
        int i=0;
        while (i+m-1<len)
        {

            int ret=FG(s,i,m);
            //cerr<<"i="<<i<<" ans="<<ans<<" ret="<<ret<<endl;
            flag=false;



            for (int j=0;j<n;j++)
            {
                if (ret==wdv[j])
                {
                    ans++;
                    flag=true;
                    break;
                }
            }
            i+=m;
            if (flag) i++;
            else
            {
                i+=ret%3;
            }
        }
        cout<<"Scenario #"<<cnt<<endl;
        cout<<ans<<endl;
        cout<<endl;
    }
    return 0;
}
