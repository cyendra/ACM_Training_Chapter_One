#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;

stack<int>stk;

int main()
{
    int ans,len;
    ans=0;
    while (!stk.empty()) stk.pop();
    cin>>s;
    len=s.length();
    for (int i=0;i<len;i++)
    {
        if (s[i]=='(')
        {
            stk.push(i);
        }
        else if (s[i]==')')
        {
            if (!stk.empty())
            {
                stk.pop();
                ans++;
            }
        }
    }
    cout<<ans*2<<endl;
    return 0;
}
