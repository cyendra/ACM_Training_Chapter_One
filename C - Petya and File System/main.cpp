#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct FOLD
{
    string name;
    int index;
    int file;
} fold[11111];

vector<int>a[11111];
map<string,int>mp;
string s;
string name;
int cnt;
int p;
vector<string>head;

int dfs(string s,bool file)
{
    string name;
    int id;
    int r=s.rfind('\\');
    if (s.find('\\')==r)
    {
        head.push_back(s);
        return 0;
    }
    name=s.substr(0,r);
    if (mp[name]==0)
    {
        mp[name]=cnt++;
        id=mp[name];
        fold[id].name=name;
        fold[id].index=id;
        if (file) fold[id].file=1;
        else fold[id].file=0;
        int get=dfs(name,false);
        if (get!=0) a[get].push_back(id);
    }
    else
    {
        id=mp[name];
        if (file) fold[id].file++;
    }
    return mp[name];
}

int dfs_findson(int u)
{
    int ret=0;
    int v;
    int l=a[u].size();
    if (l==0)
    {
        return fold[u].file;
    }
    for (int i=0;i<l;i++)
    {
        v=a[u][i];
        ret+=dfs_findson(v);
    }
    return fold[u].file+ret;
}

int dfs_findsub(int u)
{
    int ret=0;
    int v;
    int l=a[u].size();
    if (l==0)
    {
        return 1;
    }
    for (int i=0;i<l;i++)
    {
        v=a[u][i];
        ret+=dfs_findsub(v);
    }
    return ret+1;
}

int main()
{
    cnt=1;
    while (cin>>s)
    {
        dfs(s,true);
    }
    /*
    for (int i=1;i<cnt;i++)
    {
        cout<<"head i="<<i<<" "<<fold[i].name<<" son="<<fold[i].file<<endl;
        int len=a[i].size();
        for (int j=0;j<len;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    int ans_subfolders=0;
    int ans_files=0;
    int tmp;
    int len=head.size();
    for (int i=0;i<len;i++)
    {
        int id=mp[head[i]];
        tmp=dfs_findson(id);
        if (tmp>ans_files)
        {
            ans_files=tmp;
        }
        tmp=dfs_findsub(id);
        if (tmp>ans_subfolders)
        {
            ans_subfolders=tmp;
        }
    }
    cout<<ans_subfolders-1<<" "<<ans_files<<endl;
    return 0;
}
