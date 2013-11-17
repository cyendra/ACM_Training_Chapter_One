#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn=1111;
char s[maxn];
vector<int>vc;
int main()
{
    vc.clear();
    cin>>s;
    int len=strlen(s);
    for (int i=0;i<len;i++)
    {
        if (s[i]>='1'&&s[i]<='3')
        {
            vc.push_back(s[i]-'0');
        }
    }
    sort(vc.begin(),vc.end());
    cout<<vc[0];
    for (int i=1;i<(int)vc.size();i++)
    {
        cout<<"+"<<vc[i];
    }
    cout<<endl;
    return 0;
}
