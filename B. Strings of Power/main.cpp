#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;
const int maxn=111111;
string s;
LL ans;
char tc[2][10]={"heavy","metal"};
int main()
{
    LL hy=0;
    cin>>s;
    ans=0;
    int len=s.length();
    for (int i=0;i<len;i++)
    {
        if (s.substr(i,5)==tc[0]) hy++;
        if (s.substr(i,5)==tc[1]) ans+=hy;
    }
    cout<<ans<<endl;
    return 0;
}
