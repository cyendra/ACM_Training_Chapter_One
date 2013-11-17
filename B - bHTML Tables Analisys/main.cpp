#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string str,tmpstr;
int ans[11111],cnt=0;
int n;
string::iterator it;
int stk[11111]={0};
int p=0;

int main()
{
    n=0;
    while (cin>>tmpstr)
    {
        str+=tmpstr;
    }
    int len=str.length();
    int i=0;
    while (i<len)
    {
        if (str.substr(i,7)=="<table>")
        {
            i+=7;
            p++;
            //cerr<<"p="<<p<<endl;
        }
        else if (str.substr(i,4)=="<tr>")
        {
            i+=4;
        }
        else if (str.substr(i,4)=="<td>")
        {
            i+=4;
            stk[p]++;
            //cerr<<"p="<<p<<" stk[p]="<<stk[p]<<endl;
        }
        else if (str.substr(i,8)=="</table>")
        {
            i+=8;
            ans[cnt++]=stk[p];
            stk[p]=0;
            p--;
            //cerr<<"p="<<p<<endl;
        }
        else if (str.substr(i,5)=="</tr>")
        {
            i+=5;
        }
        else if (str.substr(i,5)=="</td>")
        {
            i+=5;
        }
    }
    sort(ans,ans+cnt);
    cout<<ans[0];
    for (int i=1;i<cnt;i++)
    {
        cout<<" "<<ans[i];
    }
    cout<<endl;
    return 0;
}
