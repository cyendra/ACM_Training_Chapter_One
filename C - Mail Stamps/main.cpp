#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n;
map< int , vector<int> >a;
map<int,int>d;
map<int,int>::iterator it;
map<int,bool>v;
int ans[100010];
int cd;

void dfs(int p)
{
    int len;
    len=a[p].size();
    for (int i=0;i<len;i++)
    {
        if ( v[ a[p][i] ]==false )
        {
            v[ a[p][i] ]=true;
            dfs( a[p][i] );
            break;
        }
    }
    cout<<p<<" ";
}

int main()
{
    int x,y;
    cin>>n;
    int cd=0;
    for (int i=0;i<n;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
        d[x]++;
        d[y]++;
    }
    for (it=d.begin();it!=d.end();it++)
    {
        //cout<<it->first<<" "<<it->second<<endl;
        if ( it->second==1 )
        {
            x=it->first;
            break;
        }
    }
    //cout<<x<<endl;
    v[x]=true;
    dfs(x);
    cout<<endl;
    return 0;
}
