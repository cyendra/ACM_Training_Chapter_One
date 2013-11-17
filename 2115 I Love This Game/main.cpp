#include <iostream>
#include <string>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct
{
    int tim;
    int num;
}HERO;

bool first;
int n;
HERO a[11];
map<int,string>mp;
map<int,string>::iterator it;
string str;
char tmp[100];
int m,s,tm;
bool cmp(HERO a,HERO b);
bool cmp(HERO a,HERO b)
{
    if (a.tim < b.tim)
    {
        return true;
    }
    if (a.tim > b.tim)
    {
        return false;
    }
    if (a.tim==b.tim)
    {
        if (mp[a.num]<mp[b.num])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    int n,loop;
    loop=0;
    first=true;
    while (scanf("%d",&n)!=EOF)
    {

        loop++;
        if (n==0)
        {
            break;
        }
        for (int i=0;i<n;i++)
        {
            cin >> str;
            scanf("%s",tmp);
            sscanf(tmp,"%d:%d",&m,&s);
            tm=m*60+s;
            a[i].tim=tm;
            a[i].num=i;
            mp[i]=str;
        }
        if (first==true)
        {
            first=false;
        }
        else
        {
            printf("\n");
        }
        //ºÏ—È
        /*
        for (it=mp.begin();it!=mp.end();it++)
        {
            cout << it->first << " " << it -> second <<"\n";
        }
        */
        sort(a,a+n,cmp);
        printf("Case #%d\n",loop);
        int ca=0;
        int tt=0;
        for (int i=0;i<n;i++)
        {
            cout << mp[ a[i].num ];
            if (a[i].tim!=tt )
            {
                tt=a[i].tim;
                ca=i;
            }
            printf(" %d\n",ca+1);
        }
    }
    return 0;
}
