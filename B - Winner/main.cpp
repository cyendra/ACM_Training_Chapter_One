#include <iostream>
#include <map>
using namespace std;

typedef struct{
    int cd;
    string s;
}DAT;

DAT a[1001];

map<string,int>mp,tmp;
map<string,int>::iterator it;

int n,ans,num;
string winer,str;

int main()
{
    mp.clear();
    ans=-99999;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>str>>num;
        mp[str]+=num;
        a[i].cd=num;
        a[i].s=str;
    }
    for (it=mp.begin();it!=mp.end();it++)
    {
        if ( it->second>ans )
        {
            ans=it->second;
            winer=it->first;
        }
    }
    tmp.clear();
    for (int i=0;i<n;i++)
    {
        tmp[ a[i].s ]+=a[i].cd;
        if ( mp[a[i].s]==ans && tmp[ a[i].s ]>=ans )
        {
            winer=a[i].s;
            break;
        }
    }
    cout<<winer<<endl;
    return 0;
}
