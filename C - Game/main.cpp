#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int k,n,m,q;
int a[111][111];
int b[111][111];
map<string,int>mp;
string item1[111];
string item2[111];
priority_queue<string>ans[111];
string coco[111];
int cy[111];
int hentai;

int main()
{
    string str;
    int d;
    char name[111];
    char c[111];
    cin>>k>>n>>m>>q;

    for (int i=1;i<=n;i++)
    {
        cin>>str;
        mp[str]=i;
        item1[i]=str;
    }

    for (int i=1;i<=m;i++)
    {
        scanf("%s",name);
        name[strlen(name)-1]='\0';
        mp[name]=i;
        item2[i]=name;
        int tttt;
        char cccc;
        while (scanf("%s%d%c",name,&tttt,&cccc))
        {
            b[i][mp[name]]=tttt;
            if (cccc!=',') break;
        }
    }
    //----------------------------------------
    while (q--)
    {
        cin>>d;
        cin>>str;
        a[d][mp[str]]++;
        bool ok=true;;
        for (int i=1;i<=m;i++)
        {
            ok=true;
            for (int j=1;j<=n;j++)
            {
                if (a[d][j]<b[i][j]) ok=false;
            }
            if (ok)
            {
                for (int j=1;j<=n;j++)
                {
                    a[d][j]-=b[i][j];
                }
                ans[d].push(item2[i]);
                break;
            }
        }
    }

    for (int i=1;i<=k;i++)
    {
        for (int j=1;j<=n;j++)
        {
            while (a[i][j]--)
            {
                ans[i].push(item1[j]);
            }
        }
    }

    //--------------------
    for (int i=1;i<=k;i++)
    {
        string last="1f1f1f1";
        int lastnum=-1;
        hentai=0;

        while (!ans[i].empty())
        {
            if (ans[i].top()==last)
            {
                cy[lastnum]++;
            }
            else
            {
                last=ans[i].top();
                lastnum=hentai;
                cy[hentai]=1;
                coco[hentai++]=ans[i].top();
            }
            ans[i].pop();
        }
        cout<<hentai<<endl;
        for (int i=hentai-1;i>=0;i--)
        {
            cout<<coco[i]<<" "<<cy[i]<<endl;
        }
    }
    return 0;
}
