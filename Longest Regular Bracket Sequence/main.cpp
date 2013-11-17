/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//stack<char>st;

int main()
{
    char stk[1010000];
    char s[1010000];
    bool ok;
    int maxlen=0;
    int num=0;
    int len=0;
    int p;
    //int t;
    //while (!st.empty()) st.pop();
    scanf("%s",s);
    //if ( stk[p]!='('||stk[p]!=')' ) break;
    stk[0]=s[0];
    p=1;
    ok=false;
    for (int i=1; i<strlen(s); i++)
    {
        stk[p]=s[i];
        if ( stk[p-1]=='(' && stk[p]==')' )
        {
            if (ok==false)
            {
                num++;
            }
            len+=2;
            if (len>maxlen)
            {
                maxlen=len;
            }
            p-=2;
            ok=true;
        }
        else if ( stk[p-1]==')' && stk[p]=='(' )
        {
            len=0;
            //if (ok==true) num++;
            ok=false;
        }
        else if ( stk[p-1]==')' && stk[p]==')' )
        {
            len=0;
            ok=false;
        }
        else if ( s[i-1]==')' && s[i]=='(' )
        {
            len=0;
            ok=false;
        }

        p++;
    }
    //if (ok==true)
    //{
    //    num++;
    //}
    if (maxlen==0)
    {
        printf("0 1\n");
    }
    else
    {
        printf("%d %d\n",maxlen,num);
    }
    return 0;
}


*/



#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <stack>
#include <map>
using namespace std;
stack<int> s;
int cot[1000000];
map <int,int> m;
int main()
{
    string str;
    int i,j,len;
    int top;
    while(cin>>str)
    {
        len = str.size();
        memset(cot,0,sizeof(cot));
        top = 0;
        for(i = 0;i < len;i ++)
        {
            if(str[i] == '(')
            {
                s.push(i);
            }
            else
            {
                if(s.empty()) continue;
                top += 2;
                cot[s.top()] = cot[i] = 1 ;
                s.pop();
            }
        }
        //for(i = 0;i < len;i ++) cout<<cot[i];cout<<endl;
        top = 0;
        for(i = 0;i < len;i ++)
        {
            if(cot[i] == 0) {m[top]++;top = 0;}
            else top ++;
        }
        if(top!=0)
        m[top] ++;
        int anslen = 0,anssum = 1;
        map<int,int>::iterator   it;
        for(it = m.begin();it != m.end();it ++)
        {
            if(it->first > anslen) {anslen = it->first;anssum = it->second;}
        }
        cout<<anslen<<" "<<anssum<<endl;
    }

}
