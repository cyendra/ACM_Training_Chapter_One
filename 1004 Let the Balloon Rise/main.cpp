#include <iostream>
#include <map>
using namespace std;

map<string,int>mp;
map<string,int>::iterator it;
int n,i,j;
string str;
int mx;

int main()
{
    while (cin>>n,n!=0)
    {
        mp.clear();
        for (i=0;i<n;i++)
        {
            cin>>str;
            mp[str]++;
        }
        mx=0;
        for (it=mp.begin();it!=mp.end();it++)
        {
            if (it->second>mx)
            {
                mx=it->second;
                str=it->first;
            }
        }
        cout << str << endl;
    }
    return 0;
}
