#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string,int>mp;
map<string,int>::iterator it;

int main()
{
    int n,m,a,b;
    int list[200];
    int tag[200];
    int pt;
    string str;
    cin >> n >> m;
    for (int i=0;i<n;i++)
    {
        cin >> list[i];
    }
    for (int i=0;i<m;i++)
    {
        cin >> str;
        mp[str]++;
    }
    pt=0;
    for (it=mp.begin();it!=mp.end();it++)
    {
        tag[pt]=it->second;
        pt++;
    }
    sort(list,list+n);
    sort(tag,tag+pt);
    //for (int i=0;i<pt;i++)
    //{
    //    cout << tag[i];
    //}
    //cout << endl;

    a=0;
    b=0;
    for (int i=0;i<pt;i++)
    {
        a+=list[i]*tag[pt-1-i];
    }
    for (int i=0;i<pt;i++)
    {
        b+=list[n-1-i]*tag[pt-1-i];
        //cout << b<<endl;
    }
    cout << a << " " << b << endl;
    return 0;
}
