#include <iostream>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct{
    string name;
    int point;
    int win;
    int loss;
}DAT;

map<string,DAT>mp;
map<string,DAT>::iterator it;

int n;
DAT a[60];
DAT tmp;
char str[200];
string s;
string allname[60];

bool cmp(DAT a,DAT b)
{
    int ca,cb;
    if ( a.point!=b.point )
    {
        return a.point>b.point;
    }
    else
    {
        ca=a.win-a.loss;
        cb=b.win-b.loss;
        if ( ca!=cb )
        {
            return ( ca>cb );
        }
        else
        {
            return ( a.win>b.win );
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",str);
        tmp.name=(string)str;
        tmp.point=0;
        tmp.win=0;
        tmp.loss=0;
        mp[ tmp.name ]=tmp;
    }
    for (int i=1;i<=n*(n-1)/2;i++)
    {
        int ga,gb,d;
        scanf("%s %d:%d",str,&ga,&gb);
        s=(string)str;
        d=s.find('-');
        DAT &ta=mp[ s.substr(0,d) ];
        DAT &tb=mp[ s.substr(d+1) ];
        ta.win+=ga;
        ta.loss+=gb;
        tb.win+=gb;
        tb.loss+=ga;
        if (ga>gb)
        {
            ta.point+=3;
        }
        else if (ga<gb)
        {
            tb.point+=3;
        }
        else
        {
            ta.point++;
            tb.point++;
        }
    }
    int p=0;
    for (it=mp.begin();it!=mp.end();it++)
    {
        a[p]=it->second;
        p++;
    }
    sort(a,a+p,cmp);
    for (int i=0;i<n/2;i++)
    {
        allname[i]=a[i].name;
    }
    sort( allname,allname+n/2 );
    for (int i=0;i<n/2;i++)
    {
        cout<<allname[i]<<endl;
    }
    return 0;
}
