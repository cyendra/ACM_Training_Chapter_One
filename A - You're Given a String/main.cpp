#include <iostream>

using namespace std;

string s;
int len;
int ans,t;

int main()
{
    cin>>s;
    len=s.length();
    ans=0;
    for (t=1;t<len;t++)
    {
        for (int i=0;i+t-1<len;i++)
        {
            for (int j=i+1;j+t-1<len;j++)
            {
                if (s.substr(i,t)==s.substr(j,t))
                {
                    ans=t;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
