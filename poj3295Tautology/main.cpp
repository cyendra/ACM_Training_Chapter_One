#include <iostream>
#include <stack>

using namespace std;

int qq,rr,ss,pp,tt;
string wff;
bool ok;
int ans;

stack<int>stk;
bool isbool(char c);
void done(char c);

bool isbool(char c)
{
    if (c=='p')
    {
        stk.push(pp);
        return true;
    }
    else if (c=='q')
    {
        stk.push(qq);
        return true;
    }
    else if (c=='r')
    {
        stk.push(rr);
        return true;
    }
    else if (c=='s')
    {
        stk.push(ss);
        return true;
    }
    else if (c=='t')
    {
        stk.push(tt);
        return true;
    }
    return false;
}

void done(char c)
{
    bool x,y;
    switch (c)
    {
    case 'K':
        x=stk.top();
        stk.pop();
        y=stk.top();
        stk.pop();
        stk.push(x&y);
        break;
    case 'A':
        x=stk.top();
        stk.pop();
        y=stk.top();
        stk.pop();
        stk.push(x|y);
        break;
    case 'C':
        x=stk.top();
        stk.pop();
        y=stk.top();
        stk.pop();
        stk.push(!(x)|y);
        break;
    case 'E':
        x=stk.top();
        stk.pop();
        y=stk.top();
        stk.pop();
        stk.push(x==y);
        break;
    case 'N':
        x=stk.top();
        stk.pop();
        stk.push(!x);
        break;
    }
    return;
}

int main()
{
    while (cin>>wff)
    {
        if (wff=="0") break;
        ok=true;
        for (tt=0; tt<=1; tt++)
        {
            for (pp=0; pp<=1; pp++)
            {
                for (qq=0; qq<=1; qq++)
                {
                    for (rr=0; rr<=1; rr++)
                    {
                        for (ss=0; ss<=1; ss++)
                        {
                            for (int i=wff.length()-1; i>=0; i--)
                            {
                                if (!isbool(wff[i])) done(wff[i]);
                            }
                            ans=stk.top();
                            stk.pop();
                            if (ans==false) ok=false;
                            if (!ok) break;
                        }
                        if (!ok) break;
                    }
                    if (!ok) break;
                }
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) cout<<"tautology"<<endl;
        else cout<<"not"<<endl;
    }
    return 0;
}
