#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string,int>mp;
int main()
{
    int n;
    string str;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> str;
        if ( mp[str]==0 )
        {
            mp[str]++;
            cout << "OK" << endl;
        }
        else
        {
            cout << str<<mp[str]<<endl;
            mp[str]++;

        }
    }
    return 0;
}
