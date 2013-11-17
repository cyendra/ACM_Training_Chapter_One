#include <iostream>

using namespace std;



int main()
{
    int atnum=0;
    string str;
    string ans,s;
    int len,t,l;
    bool at,flag;
    cin>>str;
    len=str.length();
    at=false;
    flag=false;
    t=0;
    ans="";
    l=-1;
    if (str[0]=='@'||str[len-1]=='@') flag=true;
    for (int i=1;i<len;i++)
    {
        if (str[i]=='@')
        {
            atnum++;
            if (l==-1) l=i;
            else if (i-l<=2)
            {
                flag=true;
                break;
            }
            else
            {
                l=i;
            }
        }
    }
    if (atnum==0) flag=true;

    for (int i=0;i<len;i++)
    {
        if (!at)
        {
            if (str[i]=='@')
            {
                at=true;
            }
        }
        else if (at&&str[i]!='@')
        {
            ans+=str.substr(t,i-t+1);
            ans+=",";
            t=i+1;
            at=false;
        }
        else if (at&&str[i]=='@')
        {
            flag=true;
            break;
        }
    }
    ans+=str.substr(t,len-t);
    len=ans.length();
    for (int i=len-1;i>=0;i--)
    {
        if (ans[i]=='@') break;
        else if (ans[i]==',')
        {
            s=ans.substr(0,i);
            s+=ans.substr(i+1,len-i+1);
            break;
        }
    }
    if (!flag)
    {
        cout<<s<<endl;
    }
    else
    {
        cout<<"No solution"<<endl;
    }
    return 0;
}
