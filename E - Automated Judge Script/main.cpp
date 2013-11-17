#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

vector<string>ac,sub;
int n,m;

bool accepted()
{
    for (int i=0;i<n;i++)
    {
        if (ac[i]!=sub[i]) return false;
    }
    return true;
}

bool PE()
{
    string num;
    string ans;
    num.clear();
    ans.clear();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<ac[i].size();j++)
        {
            if (isdigit(ac[i][j])) num+=ac[i][j];
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<sub[i].size();j++)
        {
            if (isdigit(sub[i][j])) ans+=sub[i][j];
        }
    }
    if (ans==num) return true;
    /*
    cerr<<"---"<<ans<<"---"<<num<<"---";
    if(ans==num) cerr<<"same"<<endl;
    else cerr<<"not"<<endl;
    */
    return false;
}

int main()
{
    string s;
    int cnt=0;
    while (cin>>n)
    {
        if (n==0) break;
        ac.clear();
        sub.clear();
        getchar();
        for (int i=0;i<n;i++)
        {
            getline(cin,s);
            ac.push_back(s);
        }
        cin>>m;
        getchar();
        for (int i=0;i<m;i++)
        {
            getline(cin,s);
            sub.push_back(s);
        }
        if (n==m&&accepted())
        {
            cout<<"Run #"<<++cnt<<": Accepted"<<endl;
        }
        else if (PE())
        {
            cout<<"Run #"<<++cnt<<": Presentation Error"<<endl;
        }
        else
        {
            cout<<"Run #"<<++cnt<<": Wrong Answer"<<endl;
        }
    }
    return 0;
}
