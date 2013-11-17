#include <iostream>
#include <string>
#include <algorithm>

#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define max_int       INT_MAX / 2
#define max_long      0xFFFFFFFFFFFFFFFLL / 2
#define two(a)        (1 << (a))
#define eps           1e-6
#define FF(i, a, b)   for (int i = (a); i <= (b); i++)
#define FFD(i, a, b)  for (int i = (a); i >= (b); i--)

const int OO=1e9;
const int INF=1e9;
int n;
char s[11111];
char name[4][50]={"Gryffindor","Hufflepuff","Ravenclaw","Slytherin"};

set< vector<int> >vis;

bool ans[5]={0};

void dfs(int deep, vector<int>v )
{
    if (vis.find(v)!=vis.end()) return;
    vis.insert(v);
    int min_s=*min_element(v.begin(),v.end());
    if (deep==n)
    {
        for (int i=0;i<4;i++)
        {
            if (v[i]==min_s)
            {
                ans[i]=true;
            }
        }
    }
    else if (s[deep]=='?')
    {
        for (int i=0;i<4;i++)
        {
            if (v[i]==min_s)
            {
                v[i]++;
                dfs(deep+1,v);
                v[i]--;
            }
        }
    }
    else
    {
        if (s[deep]=='G')
        {
            v[0]++;
            dfs(deep+1,v);
        }
        if (s[deep]=='H')
        {
            v[1]++;
            dfs(deep+1,v);
        }
        if (s[deep]=='R')
        {
            v[2]++;
            dfs(deep+1,v);
        }
        if (s[deep]=='S')
        {
            v[3]++;
            dfs(deep+1,v);
        }
    }
}

int main()
{
    cin>>n;
    cin>>s;
    dfs(0,vector<int>(4,0));
    for (int i=0;i<4;i++)
    {
        if (ans[i])
        {
            cout<<name[i]<<endl;
        }
    }
    return 0;
}
